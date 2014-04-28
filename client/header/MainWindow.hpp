#ifndef _MAINWINDOW_HPP_
# define _MAINWINDOW_HPP_

# define DEBUG 1
# define IPLOCAL "10.42.1.59"
# define TITLE "LostSoul v0.1"
# define WIDTH 300
# define HEIGHT 800

//inclde QT
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

//Includes CPP
# include <sstream>
# include <iostream>
# include <sstream>


class MainWindow : public QWidget
{
    Q_OBJECT
    //
    /*Login page*/
    //
public slots:
    // void        startNetsoul();
    // void        readTcpData();
public:
    MainWindow();
    ~MainWindow();
private:
    void        showVideo();
    void        initOther();
    void        initWindow();
    void        initInput();
    void        modifyStatus(QString input);
    QString     parsUser(QString input);
    void        parsData(QString input);
    QByteArray  sendAuth();
    void        initHand(QString input);
protected:
    QLabel      *_video;
    QPushButton *_go;
    QVBoxLayout *_mainLayout;
    QLineEdit   *_loginInput;
    QLineEdit   *_passwordInput;
    QString	    _md5;
    QString	    _ipclient;
    QString	    _portclient;
    int         _step;
    QString	    _username;
    QString	    _password;
    QTcpSocket  *_pSocket;
    int         _netsoul;
};

#endif /*!_MAINWINDOW_H*/
