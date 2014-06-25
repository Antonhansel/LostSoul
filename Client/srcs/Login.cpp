#include "Login.hpp"
#include "MainWindow.hpp"

Login::Login(MainWindow *window) : QWidget()
{
	_mainWindow = window;
	_window = new QWidget();
	_window->show();
    _window->setWindowTitle("LostSoul 0.5 Beta - Login");
    _window->setFixedSize(350, 800);
    initInput();
    initOther();
    _mainLayout = new QGridLayout();
    _mainLayout->addWidget(_video, 0, 0);
    _mainLayout->addWidget(_loginInput, 1, 0);
    _mainLayout->addWidget(_passwordInput, 2, 0);
    _mainLayout->addWidget(_go, 3, 0);
    _window->setLayout(_mainLayout);
    _window->setStyleSheet("color: #CFD6D7; background-color: #403075");
}

Login::~Login(){}

void	Login::initOther()
{
    showVideo();
	_go = new QPushButton();
	_go->setText("Go!");
}

void	Login::initInput()
{
	_loginInput = new QLineEdit();
	_passwordInput = new QLineEdit();
	_passwordInput->setPlaceholderText("password");
    _passwordInput->setEchoMode(QLineEdit::Password);
    _loginInput->setPlaceholderText("login");
}

void    Login::showVideo()
{
	_video = new QLabel();
    _movie = new QMovie("./images/ghost.gif");
    _video->setMovie(_movie);
    _movie->start();
}