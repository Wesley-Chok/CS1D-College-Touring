#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "studentpage.h"
#include "adminpage.h"
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/** \class MainWindow
 * Class for the main program login window (Starting screen)
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /** \fn Constructor
     * @param QWidget, parent (passed as a pointer)
     */
    MainWindow(QWidget *parent = nullptr);
    /** \fn Destructor
     * @param no formal parameters
     */
    ~MainWindow();

private slots:
    /** \fn on_loginButton_clicked()
     * when the login button on the main window is clicked, the program will check if the information in the username and password lineEdits is a valid admin login.
     * If the login is valid, the user will be sent to the adminPage. If not, the login will be rejected.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_loginButton_clicked();

    /** \fn on_clearButton_clicked()
     * when the clear button on the main window is clicked, the username and password lineEdits will be cleared.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_clearButton_clicked();

    /** \fn on_pushButton_clicked()
     * when the push button is pushed, the user will be sent to the studentPage.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui; /**< MainWindow UI variable*/
    studentpage studentObj; /**< studentpage variable*/
    adminpage adminObj; /**< adminpage variable*/

};
#endif // MAINWINDOW_H
