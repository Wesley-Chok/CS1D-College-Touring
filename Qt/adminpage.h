
#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QMainWindow>
#include "ui_adminpage.h"
#include "dbmanager.h"
#include <QtSql>
#include <QSqlQuery>
#include <QMessageBox>
#include <QInputDialog>
#include <QIntValidator>

namespace Ui {
class adminpage;
}

/** \class adminpage
 * Class for the admin side of the college tour planning program.
 */
class adminpage : public QMainWindow
{
    Q_OBJECT

public:
    /** \fn Constructor
     * @param no formal parameters
     */
    explicit adminpage(QWidget *parent = nullptr);
    /** \fn Destructor
     * @param no formal parameters
     */
    ~adminpage();

    /** \fn setupConnections()
     * Sets up the button connections between the different widget pages for the adminpage
     * @param no formal parameters
     * @return nothing returned
     */
    void setupConnections();

    /** \fn changeToAdminHomePage()
     * This function switches the ui widgets. For this one, it changes to the Admin home page.
     * @param no formal parameters
     * @return nothing returned
     */
    void changeToAdminHomePage();

    /** \fn changeToSouvenirPage()
     * This function switches the ui widgets. For this one, it changes to the changes the souvenir page.
     * @param no formal parameters
     * @return nothing returned
     */
    void changeToSouvenirPage();

    /** \fn changeToSouvenirPricePage()
     * This function switches the ui widgets. For this one, it changes to the Souvenir price page.
     * @param no formal parameters
     * @return nothing returned
     */
    void changeToSouvenirPricePage();

    /** \fn changeToSouvenirDeletePage()
     * This function switches the ui widgets. For this one, it changes to the Delete souvenir page.
     * @param no formal parameters
     * @return nothing returned
     */
    void changeToSouvenirDeletePage();

    /** \fn showSouvenirComboBoxDeletePage()
     * This function switches the ui widgets. For this one, it changes to the Delete souvenir page.
     * @param no formal parameters
     * @return nothing returned
     */
    void showSouvenirComboBoxDeletePage(QSqlQueryModel *model);

    /** \fn showCampusComboBoxAddPage(QSqlQueryModel * model)
     * This function creates values for the combo box. The setModel is created by using the loadCampusNamesOnly function in dbmanager.cpp
     * @param QSqlQueryModel, model (passed as a pointer)
     * @return nothing returned
     */
    void showCampusComboBoxAddPage(QSqlQueryModel * model);

    /** \fn showChangeSouvenirPageCampusNameComboBox(QSqlQueryModel * model)
     * This function creates calues for the combo box. The setModel is created using the loadCampusNamesOnly function in dbmanager.cpp
     * @param QSqlQueryModel, model (passed as a pointer)
     * @return nothing returned
     */
    void showchangeSouvenirPageCampusNameComboBox(QSqlQueryModel * model);

private slots:
    /** \fn on_viewDistancesBtn_clicked()
     * This function allows the user to the Distance database in its entirety through the tableView widget.
     * The QSqlQueryModel pointer is used select which database to be output using the prepare function.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_viewDistancesBtn_clicked();

    /** \fn on_viewSouvenirBtn_clicked()
     * This function allows the user to the Souvenir database in its entirety through the tableView widget.
     * The QSqlQueryModel pointer is used select which database to be output using the prepare function.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_viewSouvenirBtn_clicked();

    //*********************************************START OF STORY POINT 7A******************************************************//
    /** \fn on_addCampusThroughInputFile_clicked()
     * This function allows the user to go to the add Campus and Souvenir page.
     * To accomodate for the values in the combo box on the Campus and Souvenir page, it calls the loadSouvenirsOnly() through showSouvenirsOnly().
     * @param no formal parameters
     * @return nothing returned
     */
    void on_addCampusThroughInputFile_clicked();

    /** \fn on_addSouvenirThroughInputFile_clicked()
     * This function allows the user to go to the add specific Souvenirs entries.
     * When clicked, the button directs the user to their documents, where they can select the appropriate .txt to be read in.
     * To read the file, the QFileDialog and fstream includes are used.
     * std::string variables are converted to QString through the fromStdString function.
     * Finally, a QSqlQuery variable is used to insert the values and bind the values into the database.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_addSouvenirThroughInputFile_clicked();

    //*********************************************END OF STORY POINT 7A******************************************************//


    //*********************************************START OF STORY POINT 7B******************************************************//
    /** \fn on_changeSouvPriceBackBtn_clicked()
     * This function allows the user to go back to the main admin page. It sets the current widget to the main admin page UI.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_changeSouvPriceBackBtn_clicked();

    /** \fn on_changeSouvenirPriceBtn_clicked()
     * This function allows the user to go back to the Souvenir price page. It sets the current widget to the changeSouvenirPricePage.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_changeSouvenirPriceBtn_clicked();

    /** \fn on_updateSouvenirPriceBtn_clicked()
     * This function allows the user to change the Souvenir price on the database.
     * The QString variable souvTrad is set equal to the souvPrice
     * ChangeName_line line edit and QString variabel souvPrice is
     * set equal to the souvChangePrice_line line edit ui texts.
     * The bool variable check is used to error check the line
     * edits and is set equal to false. The for loop
     * checks the lenght of the souvPrice entry and the if statement
     * is used to check if the souvPrice entry are numbers or '.'.
     * If this is true then check will be initiliazed to true and
     * break. If the bool variable check is equal to true then it
     * will output a QMessageBox about "Invalid Input There was
     * an invalid input. Please use only Numerals(0-9) and the . ".
     * The QSqlQuery qry variable prepare is used to update the
     * Souvenirs that is set to souvTrad equal to the QString
     * variable souvTrad and souvCost equal to the QString
     * souvPrice variable where souvTrad is equal to the QString
     * variable souvTrad. If qry is executed properly then
     * it will output a QMessageBox about "Updated". Else it will
     * output a QMessageBox critical "error" with the last error.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_updateSouvenirPriceBtn_clicked();
    //*********************************************END OF STORY POINT 7B******************************************************//



    //*********************************************START OF STORY POINT 7C******************************************************//
    /** \fn on_addSouvenirBtn_clicked()
     * This function allows the user to go to the add Souvenir page. The widget will be then set to addSouvenirPage widget.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_addSouvenirBtn_clicked();

    /** \fn on_createSouvenirBtn_clicked()
     * This function allows the user to create their desired souvenir. QSqlQuery variable data
     * is used to access and insert contents of the desired database.
     * QString souvName is set equal to the souvName_line line edit
     * and QStirng souvPrice is set equal to the souvPrice_line edit
     * ui texts. The bool variable check is used to error check
     * the line edits and is set equal to false. The for loop
     * checks the lenght of the souvPrice entry and the if statement
     * is used to check if the souvPrice entry are numbers or '.'.
     * If this is true then check will be initiliazed to true and
     * break. If the bool variable check is equal to true then it
     * will output a QMessageBox about "Invalid Input There was
     * an invalid input. Please use only Numerals(0-9) and the . ".
     * Thus, the QSqlQuery variable data will prepare to insert
     * into the database Souvenirs into the values souvTrad and
     * souvCost using the QString variables souvTrad and souvCost.
     * If the data is executed properly, the it will say "Item was
     * added. Double check if an error occured.". Else, it
     * will output a QMessageBox about "Error Database not found
     * double check path to database!". Lastly, it the widget
     * will be set to the adminHomePage.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_createSouvenirBtn_clicked();
    //*********************************************END OF STORY POINT 7C******************************************************//



    //*********************************************START OF STORY POINT 7D******************************************************//
    /** \fn on_deleteSouvenirBtn_clicked()
     * This function switches to the delete page once pressed. The stacked widget ultimately changes to the delete souvenir page
     * @param no formal parameters
     * @return nothing returned
     */
    /************************************************************
     * on_deleteSouvenirBtn_clicked() - This function switches
     * to the delete page once pressed. The stacked widget ultimately
     * changes to the delete souvenir page. (By Wesley Chok)
     * **********************************************************/
    void on_deleteSouvenirBtn_clicked();

    /** \fn on_deletePageBackBtn_clicked()
     * This function allows the user to go back to the admin home page. The stacked widget ultimately changes back to the admin home page.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_deletePageBackBtn_clicked();


    /** \fn on_deleteSouvenirBtn_clicked()
     * This function allows the user to delete a Souvenir item that exists on the
     * Souvenir database. The QSqlQuery variable data is used
     * to access and delete items from the database. QString
     * variable deleteSouvenir is set equal to the value inputted
     * in the QInputDialog getText() function. The QSqlQuery
     * variable data then prepares to delete the item in Souvenir
     * where souvTrad equals the QString variable deleteSouvenir.
     * If the data is executed is equal to true then the QMessage
     * Box about outputs "The item was deleted. Double check
     * if an error occured". Finally, the widget is set to the
     * adminHomePage.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_deleteSouvenirConfirmBtn_clicked();

    //*********************************************END OF STORY POINT 7D******************************************************//

private:
    Ui::adminpage *ui; /**< adminpage UI variable*/
    dbManager database_; /**< student database manager variable*/
};
#endif // ADMINPAGE_H
