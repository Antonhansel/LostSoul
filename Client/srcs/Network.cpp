#include "Network.hpp"
#include "MainWindow.hpp"

Network::Network(MainWindow *parent)
{
	_parent = parent;
}

Network::~Network(){}

void 	Network::modifyStatus(const char *status)
{
	_parent->setStatus(QString(status));
	_parent->setConnected(true);
}

//
//HANDSHAKING STUFF	
//

void 	Network::tryNetsoul(QString username, QString password)
{
	_username = username;
	_password = password;
	std::cout << _password.toStdString() << std::endl;
	startNetsoul();
}

void	Network::readTcpData()
{
	QByteArray   	data = _pSocket->readAll();

	std::cout << data.data() << std::endl;
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
	}
		// else
		// 	parsData(data);
	// }
}

void	Network::startNetsoul()
{
	_pSocket = new QTcpSocket(this);
	connect(_pSocket, SIGNAL(readyRead()), SLOT(readTcpData()));
	_pSocket->connectToHost(IP, PORT);
	_step = 0;
	if (_pSocket->waitForConnected(50000))
		modifyStatus("Connexion established. Handshaking with server...");
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
