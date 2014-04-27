#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QtNetwork>
#include <sstream>
#include <iostream>
# include <sstream>
# include <QtCore>
# include <QFont>
# include <QPainter>
# include <QtNetwork>
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
# include <QLineEdit>
# include <QTextEdit>
# include <QString>
# include <QTime>
# include <QTimer>
# include <QMovie>
# define IP "10.42.1.59"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void        startNetsoul();
    void        readTcpData();
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void        modifyStatus(QString input);
    QString		parsUser(QString input);
    void		parsData(QString input);
    QByteArray	sendAuth();
    void        initHand(QString input);
    void        addInput(QString input);
private:
    void    showVideo();
    Ui::MainWindow *ui;
    QString	_md5;
    QString	_ipclient;
    QString	_portclient;
    int		_step;
    QString	_username;
    QString	_password;
    QTcpSocket	*_pSocket;
    int		_netsoul;
};

#endif // MAINWINDOW_H
