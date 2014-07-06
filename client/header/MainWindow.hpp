#ifndef _MAINWINDOW_HPP_
# define _MAINWINDOW_HPP_

# define DEBUG 1
# define WIDTH 300
# define HEIGHT 800
# define IP "ns-server.epitech.eu"
# define PORT 4242

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

# include <sstream>
# include <iostream>
# include <sstream>

# include "Network.hpp"
# include "Login.hpp"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow();
    ~MainWindow();
    void        initHandShake(QString, QString);
private:
protected:  
    Login       *_login;
    Network     *_network;
};

#endif /*!_MAINWINDOW_H*/
