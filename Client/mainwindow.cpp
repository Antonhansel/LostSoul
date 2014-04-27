#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("LostSoul");
    ui->_loginInput->setPlaceholderText("login");
    ui->_passwordInput->setPlaceholderText("password");
    ui->_passwordInput->setEchoMode(QLineEdit::Password);
    ui->statusBar->showMessage("Status: Offline");
    QObject::connect(ui->goButton, SIGNAL(clicked()), this,SLOT(startNetsoul(void)));
    showVideo();
}

void    MainWindow::showVideo()
{
    QMovie *movie = new QMovie("./images/ghost.gif");
    ui->video->setMovie(movie);
    movie->start();
}

void    MainWindow::modifyStatus(QString status)
{
  ui->statusBar->showMessage(status);
}

void    MainWindow::addInput(QString input)
{

}

void	MainWindow::startNetsoul()
{
  QString       input;
  QStringList	list;

  _username = ui->_loginInput->text();
  _password = ui->_passwordInput->text();
  _pSocket = new QTcpSocket(this);
  connect(_pSocket, SIGNAL(readyRead()), SLOT(readTcpData()));
  _pSocket->connectToHost(IP, 4242);
  _step = 0;
  if (_pSocket->waitForConnected())
    modifyStatus("Connexion established. Handshaking with server...");
}

void	MainWindow::initHand(QString input)
{
  int                   i;
  std::string           sub;
  std::istringstream	iss(input.toUtf8().constData());

  i = 0;
  while (iss)
    {
      sub = "";
      iss >> sub;
      if (i == 2)
    _md5 = (QString)(sub.c_str());
      if (i == 3)
    _ipclient = (QString)(sub.c_str());
      if (i == 4)
    _portclient = (QString)(sub.c_str());
      i++;
    }
}

QByteArray	MainWindow::sendAuth()
{
  QByteArray	data;
  QString       tosend;

  tosend.append(_md5);
  tosend.append('-');
  tosend.append(_ipclient);
  tosend.append('/');
  tosend.append(_portclient);
  tosend.append(_password);
  data.append(tosend);
  data = QCryptographicHash::hash(data, QCryptographicHash::Md5);
  tosend.clear();
  tosend.append("ext_user_log ");
  tosend.append(_username);
  tosend.append(" ");
  tosend.append(data.toHex());
  tosend.append(" LostSoul LostSoul\n");
  data.clear();
  data.append(tosend);
  return (data);
}

void	MainWindow::readTcpData()
{
  QByteArray   	data = _pSocket->readAll();

  if (_step == 0)
    {
      initHand(data.data());
      data = "auth_ag ext_user none none\n";
      _pSocket->write(data);
      _step++;
    }
  if (_step == 1)
    {
      _pSocket->write(sendAuth());
      _step++;
    }
  else if (_step == 2)
    {
      if (data.startsWith("rep 002 -- cmd end") == true)
        {
            _step++;
            _netsoul = 1;
            ui->loginpage->hide();
            ui->displaypage->show();
            modifyStatus("Handshaking worked! You are now netsouled!");
        }
        else
        {
           _netsoul = 0;
           modifyStatus("Handshaking failed.");
           _pSocket->close();
        }
    }
  else if (_step == 3)
    {
      if (data.startsWith("ping "))
        _pSocket->write(data);
      else
        parsData(data);
    }
}

QString		MainWindow::parsUser(QString input)
{
  QStringList		list;

  list = input.split(":");
  input.clear();
  input += "<strong>";
  input += list.at(3);
  input += "</strong>";
  return (input);
}

void		MainWindow::parsData(QString input)
{
  std::string           sub;
  std::istringstream	iss(input.toUtf8().constData());
  QUrl                  url;

  while (iss)
    {
      sub = "";
      iss >> sub;
      if (sub == "msg")
        {
            iss >> sub;
            input = parsUser(input);
            input += ": ";
            input += QString(sub.c_str());
            addInput(url.fromPercentEncoding(input.toUtf8()));
        }
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
