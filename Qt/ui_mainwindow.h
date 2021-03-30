/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *line;
    QPushButton *pushButton;
    QLineEdit *UserLineEdit;
    QPushButton *clearButton;
    QLineEdit *PWLineEdit;
    QPushButton *loginButton;
    QLabel *adminLabel;
    QLabel *UserLabel;
    QLabel *PWLabel;
    QLabel *studentLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(858, 565);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(490, 90, 20, 361));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(570, 250, 251, 91));
        UserLineEdit = new QLineEdit(centralwidget);
        UserLineEdit->setObjectName(QString::fromUtf8("UserLineEdit"));
        UserLineEdit->setGeometry(QRect(302, 230, 141, 22));
        UserLineEdit->setEchoMode(QLineEdit::Normal);
        UserLineEdit->setCursorPosition(0);
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setGeometry(QRect(340, 330, 93, 28));
        PWLineEdit = new QLineEdit(centralwidget);
        PWLineEdit->setObjectName(QString::fromUtf8("PWLineEdit"));
        PWLineEdit->setGeometry(QRect(302, 280, 141, 22));
        PWLineEdit->setEchoMode(QLineEdit::Password);
        PWLineEdit->setDragEnabled(false);
        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(210, 330, 93, 28));
        adminLabel = new QLabel(centralwidget);
        adminLabel->setObjectName(QString::fromUtf8("adminLabel"));
        adminLabel->setGeometry(QRect(230, 140, 191, 51));
        adminLabel->setAlignment(Qt::AlignCenter);
        UserLabel = new QLabel(centralwidget);
        UserLabel->setObjectName(QString::fromUtf8("UserLabel"));
        UserLabel->setGeometry(QRect(210, 230, 71, 16));
        PWLabel = new QLabel(centralwidget);
        PWLabel->setObjectName(QString::fromUtf8("PWLabel"));
        PWLabel->setGeometry(QRect(210, 280, 71, 16));
        studentLabel = new QLabel(centralwidget);
        studentLabel->setObjectName(QString::fromUtf8("studentLabel"));
        studentLabel->setGeometry(QRect(590, 140, 191, 51));
        studentLabel->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 858, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Login as Student", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        adminLabel->setText(QCoreApplication::translate("MainWindow", "Administrator", nullptr));
        UserLabel->setText(QCoreApplication::translate("MainWindow", "Username:", nullptr));
        PWLabel->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        studentLabel->setText(QCoreApplication::translate("MainWindow", "Student", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
