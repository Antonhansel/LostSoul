#include "Chat.hpp"

Chat::Chat(QString user)
{
	_user = user;
	_window = new QWidget();
	_window->show();
	QString title;
	title = "Chat with ";
	title += user;
    _window->setWindowTitle(title);

    QSize size = _window->sizeHint();
    QDesktopWidget* desktop = QApplication::desktop();
    int width = desktop->width();
    int height = desktop->height();
    int mw = size.width();
    int mh = size.height();
    int centerW = (width/2) - (mw/2);
    int centerH = (height/2) - (mh/2);
    _window->move(centerW - (350 /2), centerH - (800 /2));
    _window->setFixedSize(600, 600);
    _statusBar = new QStatusBar(_window);
    _chat = new QTextEdit();
    _chat->setReadOnly(true);
    _input = new QLineEdit();
    _mainLayout = new QGridLayout();
    _topLayout = new QGridLayout();
    _bottomLayout = new QGridLayout();
    _topLayout->addWidget(_chat, 0, 0);
    _bottomLayout->addWidget(_send, 0, 1);
    _bottomLayout->addWidget(_input, 0, 0);
    _mainLayout->addLayout(_topLayout, 0, 0);
    _mainLayout->addLayout(_bottomLayout, 1, 0);
    _mainLayout->addWidget(_statusBar, 2, 0);
    _window->setLayout(_mainLayout);
    _window->setStyleSheet("color: #CFD6D7; background-color: #0F0D24");
}

void 	addSentMessage(QString)
{

}

void 	addRecievedMessage(QString)
{

}

Chat::~Chat(){}