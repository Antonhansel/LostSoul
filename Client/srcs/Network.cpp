#include "Network.hpp"
#include "MainWindow.hpp"

Network::Network(MainWindow *parent)
{
	_parent = parent;
}

Network::~Network(){}

void 	Network::modifyStatus(const char *status, int stat)
{
	_parent->setStatus(QString(status), stat);
	_parent->setConnected(true);
}

//
//HANDSHAKING STUFF	
//

void 	Network::tryNetsoul(QString username, QString password)
{
	_username = username;
	_password = password;
	startNetsoul();
}

void 	Network::sendTcpData(QByteArray data)
{
	std::cout << data.data() << std::endl;
	_pSocket->write(data);
}

void	Network::readTcpData()
{
	QByteArray   	data = _pSocket->readAll();

	std::cout << data.data() << std::endl;
	if (_step == 0)
	{
		initHand(data.data());
		data = "auth_ag ext_user none none\n";
		sendTcpData(data);
		_step++;
	}
	else if (_step == 1)
	{
		sendTcpData(sendAuth());
		_step++;
	}
	else if (_step == 2)
	{
		if (!data.startsWith("rep 033 -- ext user identification fail"))
		{
			_step++;
			_netsoul = 1;
			modifyStatus("Handshaking worked! You are now netsouled!", 1);
		}
		else
		{
			_step = 0;
			_netsoul = 0;
			modifyStatus("Handshaking failed.", 0);
			_pSocket->close();
		}
	}
	else if (_step == 3)
	{
		if (data.startsWith("ping "))
		sendTcpData(data);
		else
			parsData(data);
	}
}

void	Network::startNetsoul()
{
	_pSocket = new QTcpSocket(this);
	connect(_pSocket, SIGNAL(readyRead()), SLOT(readTcpData()));
	_pSocket->connectToHost(IP, PORT);
	_step = 0;
	if (_pSocket->waitForConnected(50000))
		modifyStatus("Connexion established. Handshaking with server...", 0);
	else
		_netsoul = -1;
}

void	Network::initHand(QString input)
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

QString		Network::parsUser(QString input)
{
  QStringList		list;

  list = input.split(":");
  input.clear();
  input += list.at(3);
  return (input);
}

void		Network::parsData(QString input)
{
  std::string           sub;
  std::istringstream	iss(input.toUtf8().constData());
  QUrl                  url;
  QString 				user;
  QString 				message;

  while (iss)
    {
      sub = "";
      iss >> sub;
      if (sub == "msg")
        {
            iss >> sub;
            user = parsUser(input);
            message = QString(sub.c_str());
            _parent->addChat(user, message);
        }
    }
}

QByteArray	Network::sendAuth()
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
