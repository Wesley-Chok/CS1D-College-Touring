#ifndef STUDENTPAGE_H
#define STUDENTPAGE_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlQuery>
#include <QInputDialog>
#include <QIntValidator>
#include <QAbstractTableModel>

#include "dbmanager.h"

namespace Ui {

class studentpage;
}

/** \class studentpage
 * Class for the student side of the college tour planning program.
 */
class studentpage : public QMainWindow
{
    Q_OBJECT

public:
    /** \enum tour
     * Enum type for the different tour options that the user can select.
     */
    enum tour
    {
        none, /**< no tour selected*/
        uci, /**< UCI tour type selected*/
        saddleback, /**< Saddleback tour type selected*/
        asu, /**< ASU tour type selected*/
        custom /**< custom tour type selected*/
    };

    /** \struct Souvenir
     * Struct for the information about a souvenir purchased by the student.
     */
    struct Souvenir
    {
        QString souvName; /**< Souvenir name*/
        QString campus; /**< Campus of origin*/
        double cost; /**< Cost of the souvenir */
        int quantity; /**< Number of souvenirs purchased*/
    };

    //****************************************STUDENT START START****************************************
    /** \fn Constructor
     * @param QWidget, parent (passed as a pointer)
     */
    explicit studentpage(QWidget *parent = nullptr);

    /** \fn Destructor
     * @param no formal parameters
     */
    //Destructor
    ~studentpage();
    //****************************************STUDENT START END****************************************


    //****************************************STORY 1 AND 2 START****************************************
    /** \fn showDBView(QSqlQueryModel *model)
     * The table view for the campus database display UI will display the information held in a QSqlQueryModel pointer.
     * @param QSqlQueryModel, model (passed as a pointer)
     * @return nothing returned
     */
    void showDBView(QSqlQueryModel *model);

    /** \fn showCampusDBCombo(QSqlQueryModel *model)
     * The campus combo box for the campus database display UI will display the information held in a QSqlQueryModel pointer.
     * @param QSqlQueryModel, model (passed as a pointer)
     * @return nothing returned
     */
    void showCampusDBCombo(QSqlQueryModel *model);
    //****************************************STORY 1 AND 2 END****************************************


    //****************************************STORY 3 AND 8 START****************************************

    /** \fn checkCampusVectorNames(QVector<QString> campuses)
     * This function will check to if all the campuses from the vector are present in the database.
     * @param QVector<QString>, campuses
     * @return bool
     */
    bool checkCampusVectorNames(QVector<QString> campuses);
    //****************************************STORY 3 AND 8 END****************************************


    //****************************************STORY 5 START****************************************
    /** \fn showStartAvaliListView(QSqlQueryModel *model)
     * The list view on the custom tour start UI will display the information held in a QSqlQueryModel pointer.
     * @param QSqlQueryModel, model (passed as a pointer)
     * @return nothing returned
     */
    void showStartAvaliListView(QSqlQueryModel *model);

    /** \fn showStartAvaliListCombo(QSqlQueryModel *model)
     * The combo box on the custom tour start UI will display the information held in a QSqlQueryModel pointer.
     * @param QSqlQueryModel, model (passed as a pointer)
     * @return nothing returned
     */
    void showStartAvaliListCombo(QSqlQueryModel *model);
    //****************************************STORY 5 END****************************************


    //****************************************GENERAL COLLEGE SELECTION START****************************************
    /** \fn showAvaliListView(QSqlQueryModel *model)
     * The avaliable campuses list view on the general tour college selection UI will display the information held in a QSqlQueryModel pointer.
     * @param QSqlQueryModel, model (passed as a pointer)
     * @return nothing returned
     */
    void showAvaliListView(QSqlQueryModel *model);

    /** \fn showSelectListView(QSqlQueryModel *model)
     * The selected campuses list view on the general tour college selection UI will display the information held in a QSqlQueryModel pointer.
     * @param QSqlQueryModel, model (passed as a pointer)
     * @return nothing returned
     */
    void showSelectListView();

    /** \fn showAvaliListCombo(QSqlQueryModel *model)
     * The avaliable campuses combo box on the general tour college selection UI will display the information held in a QSqlQueryModel pointer.
     * @param QSqlQueryModel, model (passed as a pointer)
     * @return nothing returned
     */
    void showAvaliListCombo(QSqlQueryModel *model);
    //****************************************GENERAL COLLEGE SELECTION START****************************************


    //****************************************CALCULATION FUNCTIONS START****************************************
    /** \fn recursiveCollegeSort()
     * This function creates the optimal college touring trip plan.
     * For example, from the starting campus, the next campus will be the closest to the start, then the closest after that.
     * Each recursive call find the closest campus to the campus passed in.
     * When the closest is found, the new campus is sorted and then used for the next call.
     * @param QString, currentCamp
     * @return nothing returned
     */
    void recursiveCollegeSort(QString currentCamp);

    /** \fn calcTotalDist()
     * Using the sorted campus tour plan, the total distance traveled is calculated.
     * @param no formal parameters
     * @return nothing returned
     */
    void calcTotalDist();
    //****************************************CALCULATION FUNCTIONS START****************************************


    //****************************************STORY 6 START****************************************
    /** \fn goToSouvenirShop()
     * This function switches the current UI to the Souvenir shop UI and initializes the widgets on the UI.
     * @param no formal parameters
     * @return nothing returned
     */
    void goToSouvenirShop();

    /** \fn showSelectCampusComboBox(QStringListModel *model)
     * The campus combo box for the souvenir shop UI will display the information held in a QStringListModel pointer.
     * @param QStringListModel, model (passed as a pointer)
     * @return nothing returned
     */
    void showSelectCampusComboBox(QStringListModel *model);

    /** \fn showSouvTableView(QSqlQueryModel *model)
     * The souvenir table view for the souvenir shop UI will display the information about the souvenirs of a specified campus held in a QStringListModel pointer.
     * @param QSqlQueryModel, model (passed as a pointer)
     * @return nothing returned
     */
    void showSouvTableView(QSqlQueryModel *model);

    /** \fn showSouvCartTableView(QSqlQueryModel *model)
     * The souvenir cart table view for the souvenir shop UI will display the information about the souvenirs selected held in a QStringListModel pointer.
     * @param QSqlQueryModel, model (passed as a pointer)
     * @return nothing returned
     */
    void showSouvCartTableView(QSqlQueryModel *model);

    /** \fn showTotalCost(double itemCost)
     * Calculates the current total cost accumlated by the user's souvenir shopping, then display the current total cost to the souvenir cart cost label.
     * @param double, itemCost
     * @return nothing returned
     */
    void showTotalCost(double itemCost);
    //****************************************STORY 6 END****************************************


    //****************************************RECEIPT FUNCTIONS START****************************************
    /** \fn goToReciept()
     * This function switches the current UI to the Recipt UI and initializes the widgets on the UI.
     * Such as the final tour plan and distance, and souvenir receipt and total cost.
     * @param no formal parameters
     * @return nothing returned
     */
    void goToReceipt();
    //****************************************RECEIPT END****************************************


private slots:
    //****************************************STUDENT START START****************************************
    /** \fn on_back_button_select_clicked
     * When the back button on the main student select page is clicked, the student page window closes.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_back_button_select_clicked();
    //****************************************STUDENT START END****************************************


    //****************************************STORY 1 AND 2 START****************************************
    /** \fn on_campDB_button_clicked
     * When the campus database display button is clicked, the current UI switches to the campus database display and initializes its widgets.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_campDB_button_clicked();

    /** \fn on_other_button_clicked
     * When the other campuses button is clicked on the database display UI, the Distance database is displayed on the table view.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_other_button_clicked();

    /** \fn on_souv_button_clicked
     * When the souvenir button is clicked on the database display UI, the souvenir database for a specificed campus is displayed on the table view.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_souv_button_clicked();

    /** \fn on_back_button_db_clicked
     * When the back button is clicked on the database display UI, the current UI switches back to the main student start UI.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_back_button_db_clicked();
    //****************************************STORY 1 AND 2 END****************************************


    //****************************************STORY 3 AND 8 START****************************************
    //**********STORY 3**********
    /** \fn on_UCI_button_clicked()
     * When the UCI button is pushed, the function will check if all 11 initial campuses are present in the database.
     * If they are present, the campuses will be read in and sorted with UCI as the start.
     * The student will then be sent to the souvenir shop.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_UCI_button_clicked();

    //**********STORY 8**********
    /** \fn on_Saddle_button_clicked()
     * When the Saddleback button is pushed, the function will check if all 13 campuses (2 new) are present in the database.
     * If they are present, the campuses will be read in and sorted with Saddleback as the start.
     * The student will then be sent to the souvenir shop.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_Saddle_button_clicked();
    //****************************************STORY 3 AND 8 END****************************************


    //****************************************STORY 4 START****************************************
    /** \fn on_ASU_button_clicked()
     * When the ASU button is clicked the user will be sent to the ASU number selection UI, and the number combo box will be initialized.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_ASU_button_clicked();

    /** \fn on_enter_button_asu_clicked()
     * When the ASU number enter button is clicked, the number in the combo box is saved as the maximum number of campuses the user can select.
     * The current UI is switched to the general college selection UI.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_enter_button_asu_clicked();

    /** \fn on_back_button_asu_clicked
     * When the back button is clicked on the ASU number selection UI, the current UI switches back to the main student start UI.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_back_button_asu_clicked();
    //****************************************STORY 4 START****************************************


    //****************************************STORY 5 START****************************************
    /** \fn on_custom_button_clicked
     * When the custom button is clicked the user will be sent to the custom start selection UI, and the widgets will be initialized.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_custom_button_clicked();

    /** \fn on_enter_button_1_clicked()
     * When the enter button is clicked the user will be sent to the general custom selection UI and the student's combo box selection is saved as the starting campus.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_enter_button_1_clicked();

    /** \fn on_back_button_custom_clicked
     * When the back button is clicked on the custom start selection UI, the current UI switches back to the main student start UI.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_back_button_custom_clicked();
    //****************************************STORY 5 END****************************************


    //****************************************GENERAL COLLEGE SELECTION START****************************************
    /** \fn on_enter_button_2_clicked
     * Whenever the enter button on the general college selection UI is clicked, the campus selection in the combo box is.
     * If there are no more colleges to select, an error message will tell the student to click done.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_enter_button_2_clicked();

    /** \fn on_done_button_clicked()
     * When the done button on the general college selection UI is clicked, the current UI switches to the souvenir shop UI.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_done_button_clicked();

    /** \fn on_back_button_general_clicked
     * When the back button is clicked on the general college selection UI, the current UI switches back to the ASU start UI or the custom start UI depending on the tour type.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_back_button_general_clicked();
    //****************************************GENERAL COLLEGE SELECTION START****************************************


    //****************************************STORY 6 START****************************************
    /** \fn on_addSouvenir_button_clicked()
     * The function adds souvenirs to the souvenir cart using an accumulator string to use as the query for the database.
     * It also adds the total of the item costs in an accumulator total.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_addSouvenir_button_clicked();

    /** \fn on_selectCampus_comboBox_currentIndexChanged()
     * This function changes the souviner table depening on what campus the users has selected in the combo box.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_selectCampus_comboBox_currentIndexChanged();

    /** \fn on_checkout_button_clicked()
     * When the checkout button is clicked, the goToReceipt() function is called, and the current ui switches to the receipt UI.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_checkout_button_clicked();

    /** \fn on_backFromSouv_button_clicked()
     * When the checkout button is clicked, the goToReceipt() function is called, and the current ui switches to the receipt UI.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_backFromSouv_button_clicked();
    //****************************************STORY 6 END****************************************


    //****************************************RECEIPT FUNCTIONS START****************************************
    /** \fn on_finish_button_clicked
     * When the finish button on the receipt UI is clicked, all the changed data members are reset to default, and the current UI is switched to the main student page again.
     * @param no formal parameters
     * @return nothing returned
     */
    void on_finish_button_clicked();
    //****************************************RECEIPT FUNCTIONS END****************************************

private:
    Ui::studentpage *ui; /**< studentpage UI variable*/
    dbManager database; /**< database manager variable*/

    tour tourType; /**< enum of the current tour type*/

    QVector<QString> selectedCampuses; /**< vector of selected campuses for the tour*/
    QQueue<QString> sortedCampuses; /**< queue of sorted campuses for tour*/
    double tourDist; /**< total tour distance of the sorted tour*/

    int asuNum; /**< the maximum number of campuses allowed during the ASU tour*/
    int selectNum; /**< the current number of campuses*/

    QStack<Souvenir> souvenirCart; /**< stack of the purchased souvenirs*/
    double totalCost; /**< total cost of the purchased souvenirs*/
    QString sQry;   /**< souvenir query - ACCUMULATOR*/
};

#endif // STUDENTPAGE_H
