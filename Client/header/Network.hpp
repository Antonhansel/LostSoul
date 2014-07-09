#ifndef _NETWORK_HPP_
# define _NETWORK_HPP_

//user_cmd 922:user:1/3:chouag_m@10.12.180.160:~:
//chromesoul:epitech_2017 | msg qsdqsdqsd dst=ribeau_a$

# include <QMainWindow>
# include <QDesktopServices>
# include <QtWidgets/QApplication>
# include <QtWidgets/QPushButton>
# include <QtWidgets/QLCDNumber>
# include <QtWidgets/QColorDialog>
# include <QtWidgets/QGridLayout>
# include <QtWidgets/QHBoxLayout>
# include <QtWidgets/QGroupBox>
# include <QtWidgets/QDialog>
# include <QtWidgets/QMenuBar>
# include <QtWidgets/QMenu>
# include <QtWidgets/QAction>
# include <QtWidgets/QLabel>
# include <QtWidgets/QMessageBox>
# include <QtNetwork>
# include <QtCore>
# include <QFont>
# include <QPainter>
# include <QtNetwork>
# include <QLineEdit>
# include <QTextEdit>
# include <QString>
# include <QTime>
# include <QTimer>
# include <QMovie>
# include <QDesktopWidget>

class MainWindow;
class Network : public QWidget
{
	Q_OBJECT
public:
	Network(MainWindow *);
	~Network();
	void 	tryNetsoul(QString, QString);	
public slots:
    void        startNetsoul();
    void        readTcpData();
    void 		sendTcpData(QByteArray);
    void 		parsData(QString);
    QString		parsUser(QString);
private:
	void 		initHand(QString);
	QByteArray 	sendAuth();
	void 		modifyStatus(const char *, int);
private:
	MainWindow *_parent;
	QString	    _md5;
	QString	    _ipclient;
	QString	    _portclient;
	int         _step;
	QString	    _username;
	QString	    _password;
	QTcpSocket  *_pSocket;
	int         _netsoul;
};

#endif /*_NETWORK_HPP_*/