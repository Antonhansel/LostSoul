#include "Login.hpp"
#include "MainWindow.hpp"

Login::Login(MainWindow *window) : QWidget()
{
	_mainWindow = window;
	_window = new QWidget();
	_window->show();
    _window->setWindowTitle("LostSoul 0.5 Beta - Login");

    QSize size = _window->sizeHint();
    QDesktopWidget* desktop = QApplication::desktop();
    int width = desktop->width();
    int height = desktop->height();
    int mw = size.width();
    int mh = size.height();
    int centerW = (width/2) - (mw/2);
    int centerH = (height/2) - (mh/2);
    _window->move(centerW - (350 /2), centerH - (800 /2));
    _window->setFixedSize(325, 800);
    initInput();
    initOther();
    QLabel *image = new QLabel();
    image->setPixmap(QPixmap("./images/text.png"));
    image->setFixedSize(300, 100);
    _statusBar = new QStatusBar(_window);
    _mainLayout = new QGridLayout();
    _mainLayout->addWidget(image, 0, 0);
    _mainLayout->addWidget(_video, 1, 0);
    _mainLayout->addWidget(_loginInput, 2, 0);
    _mainLayout->addWidget(_passwordInput, 3, 0);
    _mainLayout->addWidget(_go, 4, 0);
    _mainLayout->addWidget(_statusBar, 5, 0);
    _window->setLayout(_mainLayout);
    _window->setStyleSheet("color: #CFD6D7; background-color: #0F0D24");
}

Login::~Login(){}

void    Login::setStatus(QString status, int stat)
{
    _statusBar->showMessage(status);
    if (stat)
        _window->hide();
}

void    Login::initConnexion()
{
    _mainWindow->initHandShake(_loginInput->text(), _passwordInput->text());
}

void	Login::initOther()
{
    showVideo();
    _go = new QPushButton();
    _go->setText("Go!");
    connect(_go, SIGNAL(clicked()), SLOT(initConnexion()));
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