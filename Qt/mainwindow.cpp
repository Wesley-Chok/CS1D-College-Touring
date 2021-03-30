#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QMessageBox>
#include <QFont>
#include "QDebug"

/*
 * Constructor
 * IN: QWidget, parent (passed as a pointer)
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
/*
 * Destructor
 * IN: no formal parameters
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * on_loginButton_clicked()
 * when the login button on the main window is clicked, the program will check if the information in the username and password lineEdits is a valid admin login.
 * If the login is valid, the user will be sent to the adminPage. If not, the login will be rejected.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void MainWindow::on_loginButton_clicked()
{
    if(ui->UserLineEdit->text() == "admin" && ui->PWLineEdit->text() == "potato")
    {
       //ADMIN PAGE
       QMessageBox::information(this, "Welcome, Admin!", "Now moving to Main Admin Screen...", QMessageBox::Ok, QMessageBox::NoButton);
       adminObj.show();
    }
    else
       QMessageBox::critical(this, "Access Denied", "INCORRECT LOGIN", QMessageBox::Ok, QMessageBox::NoButton);

}

/*
 * on_clearButton_clicked()
 * when the clear button on the main window is clicked, the username and password lineEdits will be cleared.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void MainWindow::on_clearButton_clicked()
{
    ui->UserLineEdit->setText("");
    ui->PWLineEdit->setText("");
}

/*
 * on_pushButton_clicked()
 * when the push button is pushed, the user will be sent to the studentPage.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this, "Welcome, Student!", "Now moving to Main Student Screen...", QMessageBox::Ok, QMessageBox::NoButton);
    studentObj.show();
}
