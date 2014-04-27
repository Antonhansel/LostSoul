/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *loginPage;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *layout;
    QLabel *video;
    QLineEdit *_loginInput;
    QLineEdit *_passwordInput;
    QPushButton *goButton;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(336, 603);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(0, 26, 54, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        MainWindow->setPalette(palette);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        loginPage = new QFrame(centralWidget);
        loginPage->setObjectName(QStringLiteral("loginPage"));
        loginPage->setEnabled(true);
        loginPage->setGeometry(QRect(10, 10, 311, 541));
        loginPage->setFrameShape(QFrame::StyledPanel);
        loginPage->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget = new QWidget(loginPage);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 291, 501));
        layout = new QVBoxLayout(verticalLayoutWidget);
        layout->setSpacing(6);
        layout->setContentsMargins(11, 11, 11, 11);
        layout->setObjectName(QStringLiteral("layout"));
        layout->setContentsMargins(0, 0, 0, 0);
        video = new QLabel(verticalLayoutWidget);
        video->setObjectName(QStringLiteral("video"));

        layout->addWidget(video);

        _loginInput = new QLineEdit(verticalLayoutWidget);
        _loginInput->setObjectName(QStringLiteral("_loginInput"));

        layout->addWidget(_loginInput);

        _passwordInput = new QLineEdit(verticalLayoutWidget);
        _passwordInput->setObjectName(QStringLiteral("_passwordInput"));

        layout->addWidget(_passwordInput);

        goButton = new QPushButton(verticalLayoutWidget);
        goButton->setObjectName(QStringLiteral("goButton"));

        layout->addWidget(goButton);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 336, 25));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        video->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        goButton->setText(QApplication::translate("MainWindow", "Go!", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
