#ifndef LOGIN_HPP_
# define LOGIN_HPP_

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

class MainWindow;
class Login : public QWidget
{
	Q_OBJECT
public:
	Login(MainWindow *);
	~Login();
private:
	void 	initOther();
	void 	initInput();
	void 	showVideo();
private:
	QMovie 		*_movie;
	QWidget 	*_window;
	MainWindow	*_mainWindow;
	Login 		*_login;
    QLabel      *_video;
    QPushButton *_go;
    QGridLayout *_mainLayout;
    QLineEdit   *_loginInput;
    QLineEdit   *_passwordInput;
};

#endif /* LOGIN_HPP_ */