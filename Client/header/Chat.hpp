#ifndef _CHAT_HPP_
# define _CHAT_HPP_

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
# include <QGraphicsPixmapItem>
# include <QStatusBar>

class Chat : public QWidget
{
	Q_OBJECT
public:
	Chat(QString user);
	~Chat();
private:
	void 	addSentMessage(QString);
	void 	addRecievedMessage(QString);
private:
	QWidget 		*_window;
	QString		_user;
	QStatusBar	*_statusBar;
	QGridLayout	*_mainLayout;
	QTextEdit 	*_chat;
	QLineEdit	*_input;
	QPushButton	*_send;
	QGridLayout	*_topLayout;
	QGridLayout	*_bottomLayout;
};

#endif /*_CHAT_HPP_*/