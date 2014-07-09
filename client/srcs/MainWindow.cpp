# include "MainWindow.hpp"

MainWindow::MainWindow() : QWidget()
{
    _login = new Login(this);
    _network = new Network(this);
    _connected = false;
    
}

MainWindow::~MainWindow()
{

}

void 	MainWindow::addChat(QString user, QString message)
{
	Chat *test;
	test = new Chat(user);
}

void 	MainWindow::initHandShake(QString username, QString password)
{
	_network->tryNetsoul(username, password);
}

void 	MainWindow::setStatus(QString status, int stat)
{
	_login->setStatus(status, stat);
}

void 	MainWindow::setConnected(bool connected)
{
	_connected = connected;
}
