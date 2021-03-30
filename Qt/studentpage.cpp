#include "studentpage.h"
#include <QMessageBox>
#include <QComboBox>
#include "ui_studentpage.h"
#include <iomanip>

//****************************************STUDENT START START****************************************
/*
 * Constructor
 * IN: QWidget, parent (passed as a pointer)
 */
studentpage::studentpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::studentpage)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentWidget(ui->StudentSelect);

    showCampusDBCombo(database.loadCampusNamesOnly());

    tourType = none;
    asuNum = 0;
    selectNum = 0;
    totalCost = 0.00;
}

/*
 * Destructor
 * IN: no formal parameters
 */
studentpage::~studentpage()
{
    delete ui;
    database.deleteCart();
}

//MAIN STUDENT PAGE BACK BUTTON
/*
 * on_back_button_select_clicked
 * When the back button on the main student select page is clicked, the student page window closes.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void studentpage::on_back_button_select_clicked()
{
    studentpage::close();
}
//****************************************STUDENT START END****************************************

//****************************************STORY 1 AND 2 START****************************************
/*
 * showDBView(QSqlQueryModel *model)
 * The table view for the campus database display UI will display the information held in a QSqlQueryModel pointer.
 * IN: QSqlQueryModel, model (passed as a pointer)
 * OUT: nothing returned
 */
void studentpage::showDBView(QSqlQueryModel *model)
{
    ui->tableView->setModel(model);
}

/*
 * showCampusDBCombo(QSqlQueryModel *model)
 * The campus combo box for the campus database display UI will display the information held in a QSqlQueryModel pointer.
 * IN: QSqlQueryModel, model (passed as a pointer)
 * OUT: nothing returned
 */
void studentpage::showCampusDBCombo(QSqlQueryModel *model)
{
    ui->campus_combo->setModel(model);
}

/*
 * on_campDB_button_clicked
 * When the campus database display button is clicked, the current UI switches to the campus database display and initializes its widgets.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void studentpage::on_campDB_button_clicked()
{
    QMessageBox::information(this, "Loading...", "Now moving to Database Viewing Screen.", QMessageBox::Ok, QMessageBox::NoButton);
    ui->stackedWidget->setCurrentWidget(ui->databaseDisplay);
    showCampusDBCombo(database.loadCampusNamesOnly());
}

/*
 * on_other_button_clicked
 * When the other campuses button is clicked on the database display UI, the Distance database is displayed on the table view.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void studentpage::on_other_button_clicked()
{
    ui->database_label->setText(ui->campus_combo->currentText());
    showDBView(database.loadOtherCampusAndDist(ui->campus_combo->currentText()));
    ui->tableView->setColumnWidth(0, 450);
    ui->tableView->setColumnWidth(1, 280);
}

/*
 * on_souv_button_clicked
 * When the souvenir button is clicked on the database display UI, the souvenir database for a specificed campus is displayed on the table view.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void studentpage::on_souv_button_clicked()
{
    ui->database_label->setText(ui->campus_combo->currentText());
    showDBView(database.loadCampusSouvenirs(ui->campus_combo->currentText()));
    ui->tableView->setColumnWidth(0, 460);
    ui->tableView->setColumnWidth(1, 280);
}

/*
 * on_back_button_db_clicked
 * When the back button is clicked on the database display UI, the current UI switches back to the main student start UI.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void studentpage::on_back_button_db_clicked()
{
    QMessageBox::information(this, "Loading...", "Now moving to Main Student Screen.", QMessageBox::Ok, QMessageBox::NoButton);
    ui->stackedWidget->setCurrentWidget(ui->StudentSelect);
}
//****************************************STORY 1 AND 2 END****************************************

//****************************************STORY 3 AND 8 START****************************************
/*
 * checkCampusVectorNames(QVector<QString> campuses)
 * This function will check to if all the campuses from the vector are present in the database.
 * IN: QVector<QString>, campuses
 * OUT: bool
 */
bool studentpage::checkCampusVectorNames(QVector<QString> campuses)
{
    bool found = true;
    QString *p = campuses.begin();
    while (p != campuses.end() && found == true)
    {
        if(!database.checkCampusName(*p))
        {
            found = false;

        }
        else
        {
            p++;
        }
    }
    return found;
}

//**********STORY 3**********
/*
 * on_UCI_button_clicked()
 * When the UCI button is pushed, the function will check if all 11 initial campuses are present in the database.
 * If they are present, the campuses will be read in and sorted with UCI as the start.
 * The student will then be sent to the souvenir shop.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void studentpage::on_UCI_button_clicked()
{
    QVector<QString> initial11{"University of California, Irvine (UCI)",
                               "Arizona State University",
                               "Massachusetts Institute of Technology (MIT)",
                               "Northwestern",
                               "Ohio State University",
                               "Saddleback College",
                               "University of  Michigan",
                               "University of California, Los Angeles (UCLA)",
                               "University of Oregon",
                               "University of Wisconsin",
                               "University of the Pacific",
                               };

    bool allFound = checkCampusVectorNames(initial11);

    if(!allFound)
    {
        QMessageBox::warning(this, "ERROR", "NOT ALL 11 INITIAL CAMPUSES ARE IN THE DATABASE. ADMINISTRATOR ACTION NEEDED.", QMessageBox::Ok, QMessageBox::NoButton);
    }
    else
    {
        selectedCampuses.append(initial11);
        tourType = uci;

        //send to souvenir shop
        QMessageBox::information(this, "Loading...", "UCI tour type has been selected. Now moving to Souviner Shop Screen.", QMessageBox::Ok, QMessageBox::NoButton);
        goToSouvenirShop();
    }
}

//**********STORY 8**********
/*
 * on_Saddle_button_clicked()
 * When the Saddleback button is pushed, the function will check if all 13 campuses (2 new) are present in the database.
 * If they are present, the campuses will be read in and sorted with Saddleback as the start.
 * The student will then be sent to the souvenir shop.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void studentpage::on_Saddle_button_clicked()
{
    QVector<QString> campus13{"Saddleback College",
                               "Arizona State University",
                               "Massachusetts Institute of Technology (MIT)",
                               "Northwestern",
                               "Ohio State University",
                               "University of California, Irvine (UCI)",
                               "University of  Michigan",
                               "University of California, Los Angeles (UCLA)",
                               "University of Oregon",
                               "University of Wisconsin",
                               "University of the Pacific",
                               "California State University, Fullerton",
                               "University of Texas"};

    bool allFound = checkCampusVectorNames(campus13);

    if(!allFound)
    {
         QMessageBox::warning(this, "ERROR", "NOT ALL 13 CAMPUSES ARE IN THE DATABASE. ADMINISTRATOR ACTION NEEDED.", QMessageBox::Ok, QMessageBox::NoButton);
    }
    else
    {
        selectedCampuses.append(campus13);
        tourType = saddleback;

        //go to souvenir shop
        QMessageBox::information(this, "Loading...", "Saddleback tour type has been selected. Now moving to Souvenir Screen.", QMessageBox::Ok, QMessageBox::NoButton);
        goToSouvenirShop();
    }
}
//****************************************STORY 3 AND 8 END****************************************

//****************************************STORY 4 START****************************************
/*
 * on_ASU_button_clicked()
 * When the ASU button is clicked the user will be sent to the ASU number selection UI, and the number combo box will be initialized.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void studentpage::on_ASU_button_clicked()
{

    tourType = asu;
    int campusCount = database.GetCampusCount("Arizona State University");
    for(int i = 1; i <= campusCount; i++)
    {
        ui->asu_combo->addItem(QString::number(i));
    }
    QMessageBox::information(this, "Loading...", "ASU tour type has been selected. Now moving to ASU Number Selection Screen.", QMessageBox::Ok, QMessageBox::NoButton);
    ui->stackedWidget->setCurrentWidget(ui->asuCollegeTour);
}

/*
 * on_enter_button_asu_clicked()
 * When the ASU number enter button is clicked, the number in the combo box is saved as the maximum number of campuses the user can select.
 * The current UI is switched to the general college selection UI.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void studentpage::on_enter_button_asu_clicked()
{
    selectedCampuses.push_back("Arizona State University");
    selectNum++;
    asuNum = ui->asu_combo->currentIndex() + 1;

    //The program leaves the start screen to the main tour planning screen
    QMessageBox::information(this, "Loading...", "Maximum number of visitable campuses has been selected. Now moving to College Selection Screen.", QMessageBox::Ok, QMessageBox::NoButton);
    ui->stackedWidget->setCurrentWidget(ui->collegeTour);

    //Populates the main tour planning screen Avaliable Campuses list view with the names of the campuses
    showAvaliListView(database.loadRemainingCampusNamesOnly(selectedCampuses));
    //Populates the main tour planning screen Selected Campus list view with the names of the campueses
    showSelectListView();
    //Populates the main tour planning screen Avaliable Campuses combo box with the names of the campuses
    showAvaliListCombo(database.loadRemainingCampusNamesOnly(selectedCampuses));
}

/*
 * on_back_button_asu_clicked
 * When the back button is clicked on the ASU number selection UI, the current UI switches back to the main student start UI.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void studentpage::on_back_button_asu_clicked()
{
    tourType = none;QMessageBox::information(this, "Loading...", "Now moving to Main Student Screen.", QMessageBox::Ok, QMessageBox::NoButton);
    ui->stackedWidget->setCurrentWidget(ui->StudentSelect);

}
//****************************************STORY 4 END****************************************

//****************************************STORY 5 START****************************************
/*
 * showStartAvaliListView(QSqlQueryModel *model)
 * The list view on the custom tour start UI will display the information held in a QSqlQueryModel pointer.
 * IN: QSqlQueryModel, model (passed as a pointer)
 * OUT: nothing returned
 */
void studentpage::showStartAvaliListView(QSqlQueryModel *model)
{
    ui->start_listView->setModel(model);
}

/*
 * showStartAvaliListCombo(QSqlQueryModel *model)
 * The combo box on the custom tour start UI will display the information held in a QSqlQueryModel pointer.
 * IN: QSqlQueryModel, model (passed as a pointer)
 * OUT: nothing returned
 */
void studentpage::showStartAvaliListCombo(QSqlQueryModel *model)
{
    ui->start_combo->setModel(model);
}

/*
 * on_custom_button_clicked
 * When the custom button is clicked the user will be sent to the custom start selection UI, and the widgets will be initialized.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void studentpage::on_custom_button_clicked()
{
    tourType = custom;
    QMessageBox::information(this, "Loading...", "Custom tour type has been selected. Now moving to Starting Campus Selection Screen.", QMessageBox::Ok, QMessageBox::NoButton);
    ui->stackedWidget->setCurrentWidget(ui->startCollegeTour);

    showStartAvaliListView(database.loadCampusNamesOnly());
    showStartAvaliListCombo(database.loadCampusNamesOnly());
}

/*
 * on_enter_button_1_clicked()
 * When the enter button is clicked the user will be sent to the general custom selection UI and the student's combo box selection is saved as the starting campus.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void studentpage::on_enter_button_1_clicked()
{
    //Students choice is saved into the vector
    QString campus = ui->start_combo->currentText();
    selectedCampuses.push_back(campus);
    selectNum++;

    //The program leaves the start screen to the main tour planning screen
    QMessageBox::information(this, "Loading...", "Starting campus has been selected. Now moving to College Selection Screen.", QMessageBox::Ok, QMessageBox::NoButton);
    ui->stackedWidget->setCurrentWidget(ui->collegeTour);

    //Populates the main tour planning screen Avaliable Campuses list view with the names of the campuses
    showAvaliListView(database.loadRemainingCampusNamesOnly(selectedCampuses));
    //Populates the main tour planning screen Selected Campus list view with the names of the campueses
    showSelectListView();
    //Populates the main tour planning screen Avaliable Campuses combo box with the names of the campuses
    showAvaliListCombo(database.loadRemainingCampusNamesOnly(selectedCampuses));
}

/*
 * on_back_button_custom_clicked
 * When the back button is clicked on the custom start selection UI, the current UI switches back to the main student start UI.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void studentpage::on_back_button_custom_clicked()
{
    QMessageBox::information(this, "Loading...", "Now moving to Main Student Screen.", QMessageBox::Ok, QMessageBox::NoButton);
    tourType = none;
    ui->stackedWidget->setCurrentWidget(ui->StudentSelect);
}

//****************************************STORY 5 END****************************************

//****************************************GENERAL COLLEGE SELECTION START****************************************
/*
 * showAvaliListView(QSqlQueryModel *model)
 * The avaliable campuses list view on the general tour college selection UI will display the information held in a QSqlQueryModel pointer.
 * @param QSqlQueryModel, model (passed as a pointer)
 * @return nothing returned
 */
void studentpage::showAvaliListView(QSqlQueryModel *model)
{
    ui->avali_listView->setModel(model);
}

/*
 * showSelectListView(QSqlQueryModel *model)
 * The selected campuses list view on the general tour college selection UI will display the information held in a QSqlQueryModel pointer.
 * IN: QSqlQueryModel, model (passed as a pointer)
 * OUT: nothing returned
 */
void studentpage::showSelectListView()
{
    ui->select_listView->setModel(new QStringListModel(QList<QString>::fromVector(selectedCampuses)));
}

/*
 * showAvaliListCombo(QSqlQueryModel *model)
 * The avaliable campuses combo box on the general tour college selection UI will display the information held in a QSqlQueryModel pointer.
 * IN: QSqlQueryModel, model (passed as a pointer)
 * OUT: nothing returned
 */
void studentpage::showAvaliListCombo(QSqlQueryModel *model)
{
    ui->next_combo->setModel(model);
}

/*
 * on_enter_button_2_clicked
 * Whenever the enter button on the general college selection UI is clicked, the campus selection in the combo box is.
 * If there are no more colleges to select, an error message will tell the student to click done.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void studentpage::on_enter_button_2_clicked()
{
    QString campus = ui->next_combo->currentText();
    //No campuses
    if(campus == "")
    {
        QMessageBox::warning(this, "ERROR", "NO MORE CAMPUSES! PLEASE CLICK DONE!", QMessageBox::Ok, QMessageBox::NoButton);
    }
    //ASU tour
    else if (selectNum == asuNum)
    {
        QMessageBox::warning(this, "ERROR", "YOU HAVE REACHED YOUR MAX FOR THE ASU TOUR! PLEASE CLICK DONE!", QMessageBox::Ok, QMessageBox::NoButton);
    }
    //Campuses remain
    else
    {
        //Pushes newly selected campus to the back of the vector
        selectedCampuses.push_back(campus);
        selectNum++;
        //Refreshes list views and combo box
        showAvaliListView(database.loadRemainingCampusNamesOnly(selectedCampuses));
        showSelectListView();
        showAvaliListCombo(database.loadRemainingCampusNamesOnly(selectedCampuses));
    }
}

/*
 * on_done_button_clicked()
 * When the done button on the general college selection UI is clicked, the current UI switches to the souvenir shop UI.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void studentpage::on_done_button_clicked()
{
    if(asuNum == 0 || selectNum == asuNum)
    {
        //Go to souvenirShop widget
        QMessageBox::information(this, "Loading...", "Now moving to Souvenir Shop Screen.", QMessageBox::Ok, QMessageBox::NoButton);
        goToSouvenirShop();
    }
    else
    {
        int left = asuNum - selectNum;
        QMessageBox::warning(this, "ERROR", "PLEASE SELECT " + QString::number(left) + " MORE CAMPUSES.", QMessageBox::Ok, QMessageBox::NoButton);
    }
}

/*
 * on_back_button_general_clicked
 * When the back button is clicked on the general college selection UI, the current UI switches back to the ASU start UI or the custom start UI depending on the tour type.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void studentpage::on_back_button_general_clicked()
{
    while(!selectedCampuses.empty())
    {
          selectedCampuses.pop_back();
    }
    asuNum = 0;
    selectNum = 0;

    if(tourType == asu)
    {
        QMessageBox::information(this, "Loading...", "ASU tour reseting. Now moving to ASU Number Select Screen.", QMessageBox::Ok, QMessageBox::NoButton);
          ui->stackedWidget->setCurrentWidget(ui->asuCollegeTour);
    }
    else if(tourType == custom)
    {
        QMessageBox::information(this, "Loading...", "Custom tour reseting. Now moving to Starting Campus Selection Screen.", QMessageBox::Ok, QMessageBox::NoButton);
          ui->stackedWidget->setCurrentWidget(ui->startCollegeTour);
    }
    totalCost = 0;
    sQry.clear();
}

//****************************************GENERAL COLLEGE SELECTION START****************************************

//****************************************CALCULATION FUNCTIONS START****************************************
/*
 * recursiveCollegeSort()
 * This function creates the optimal college touring trip plan.
 * For example, from the starting campus, the next campus will be the closest to the start, then the closest after that.
 * Each recursive call find the closest campus to the campus passed in.
 * When the closest is found, the new campus is sorted and then used for the next call.
 * IN: QString, currentCamp
 * OUT: nothing returned
 */
void studentpage::recursiveCollegeSort(QString currentCamp)
{
   sortedCampuses.enqueue(currentCamp);
   selectedCampuses.removeAll(currentCamp);

   if(selectedCampuses.isEmpty())
   {
       return;
   }
   else
   {
        QString* otherCamp = selectedCampuses.begin();
        int currentIndex = 0;

        double leastDist = database.GetDistBtwn(currentCamp, *otherCamp);
        int leastIndex = 0;

        otherCamp++;
        currentIndex++;

        while(otherCamp != selectedCampuses.end())
        {
            double currentDist = database.GetDistBtwn(currentCamp, *otherCamp);
            if (currentDist < leastDist)
            {
                leastDist = currentDist;
                leastIndex = currentIndex;
            }
            else
            {
                otherCamp++;
                currentIndex++;
            }
        }
        QString nextCamp = selectedCampuses.at(leastIndex);
        recursiveCollegeSort(nextCamp);
   }
}

/*
 * calcTotalDist()
 * Using the sorted campus tour plan, the total distance traveled is calculated.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void studentpage::calcTotalDist()
{
    tourDist = 0;
    for(int i = 1; i < sortedCampuses.count(); i++)
    {
        double currentDistBtwn = database.GetDistBtwn(sortedCampuses[i-1], sortedCampuses[i]);
        tourDist += currentDistBtwn;
    }
}
//****************************************CALCULATION FUNCTIONS END****************************************

//****************************************STORY 6 START****************************************
/*
 * goToSouvenirShop()
 * This function switches the current UI to the Souvenir shop UI and initializes the widgets on the UI.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void studentpage::goToSouvenirShop()
{
    //Go to souvenirShop widget
    ui->stackedWidget->setCurrentWidget(ui->souvenirShop);
    showSouvTableView(database.loadCampusSouvenirs(""));
    showSelectCampusComboBox(new QStringListModel(QList<QString>::fromVector(selectedCampuses)));

    showSouvTableView(database.loadCampusSouvenirs(ui->selectCampus_comboBox->currentText()));
    //create Cart table
    database.createCart();
    showSouvCartTableView(database.loadSouvCart(sQry));
    showTotalCost(totalCost);

}

/*
 * showSelectCampusComboBox(QStringListModel *model)
 * The campus combo box for the souvenir shop UI will display the information held in a QStringListModel pointer.
 * IN: QStringListModel, model (passed as a pointer)
 * OUT: nothing returned
 */
void studentpage::showSelectCampusComboBox(QStringListModel *model)
{
    ui ->selectCampus_comboBox->setModel(model);
}

/*
 * showSouvTableView(QSqlQueryModel *model)
 * The souvenir table view for the souvenir shop UI will display the information about the souvenirs of a specified campus held in a QStringListModel pointer.
 * IN: QSqlQueryModel, model (passed as a pointer)
 * OUT: nothing returned
 */
void studentpage::showSouvTableView(QSqlQueryModel *model)
{
    ui->souv_tableView->setModel(model);
    ui->souv_comboBox->setModel(model);
}

/*
 * showSouvCartTableView(QSqlQueryModel *model)
 * The souvenir cart table view for the souvenir shop UI will display the information about the souvenirs selected held in a QStringListModel pointer.
 * IN: QSqlQueryModel, model (passed as a pointer)
 * OUT: nothing returned
 */
void studentpage::showSouvCartTableView(QSqlQueryModel *model)
{
    ui->souvCart_tableView->setModel(model);
}

/*
 * showTotalCost(double itemCost)
 * Calculates the current total cost accumlated by the user's souvenir shopping, then display the current total cost to the souvenir cart cost label.
 * IN: double, itemCost
 * OUT: nothing returned
 */
void studentpage::showTotalCost(double itemCost)
{
    totalCost += itemCost;
    QString totalCostStr = QString::number(totalCost, 'f', 2);
    ui->totalCart_label->setText(totalCostStr);
}

/*
 * on_addSouvenir_button_clicked()
 * The function adds souvenirs to the souvenir cart using an accumulator string to use as the query for the database.
 * It also adds the total of the item costs in an accumulator total.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void studentpage::on_addSouvenir_button_clicked()
{
    Souvenir souv;
    //name and campus
    QString name, campus;
    name = ui->souv_comboBox->currentText();
    souv.souvName = name;
    campus = ui->selectCampus_comboBox->currentText();
    souv.campus = campus;


    //quantity and item cost
    int quantity = ui-> quantity_spinBox -> cleanText().toInt();
    souv.quantity = quantity;
    double itemCost = database.GetTotalCost(campus, name);
    itemCost = itemCost * quantity;
    souv.cost = itemCost;

    souvenirCart.push(souv);

    //update Cart table
    database.updateCartQuantity(campus, name, quantity);

    //displays cart in table
   if(sQry == "")
   {
       sQry += "select souvCollege as 'College', souvTrad as 'Souvenirs', souvCost as 'Cost', quantity as 'Quantity' "
                       "from Cart where souvCollege = '" +campus+ "' and souvTrad = '" +name+ "'";
   }
   else
   {
       sQry += " union select souvCollege as 'College', souvTrad as 'Souvenirs', souvCost as 'Cost', quantity as 'Quantity'"
                       "from Cart where souvCollege = '" +campus+ "' and souvTrad = '" +name+ "'";
   }

   showSouvCartTableView(database.loadSouvCart(sQry));

  // showSouvCartTableView();
   showTotalCost(itemCost);

}

/*
 * on_selectCampus_comboBox_currentIndexChanged()
 * This function changes the souviner table depening on what campus the users has selected in the combo box.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void studentpage::on_selectCampus_comboBox_currentIndexChanged()
{
    QString campus = ui->selectCampus_comboBox->currentText();
    showSouvTableView(database.loadCampusSouvenirs(campus));
}

///Ivan
/*
 * on_checkout_button_clicked()
 * When the checkout button is clicked, the goToReceipt() function is called, and the current ui switches to the receipt UI.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void studentpage::on_checkout_button_clicked()
{
    QMessageBox::information(this, "Loading...", "Shopping Complete. Now moving to Receipt Screen.", QMessageBox::Ok, QMessageBox::NoButton);
    goToReceipt();
}

/*
 * on_backFromSouv_button_clicked()
 * When the checkout button is clicked, the goToReceipt() function is called, and the current ui switches to the receipt UI.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void studentpage::on_backFromSouv_button_clicked()
{
    if(tourType == uci || tourType == saddleback)
    {
        while(!selectedCampuses.empty())
        {
            selectedCampuses.pop_front();
        }
        totalCost = 0;
        sQry.clear();
        if(tourType == uci)
            QMessageBox::information(this, "Loading...", "UCI tour reseting. Now moving to Main Student Screen.", QMessageBox::Ok, QMessageBox::NoButton);
        else
            QMessageBox::information(this, "Loading...", "Saddleback tour reseting. Now moving to Main Student Screen.", QMessageBox::Ok, QMessageBox::NoButton);
        ui->stackedWidget->setCurrentWidget(ui->StudentSelect);
    }
    else
    {
         QMessageBox::information(this, "Loading...", "Now moving to College Selection Screen.", QMessageBox::Ok, QMessageBox::NoButton);
        ui->stackedWidget->setCurrentWidget(ui->collegeTour);
    }

}
//****************************************STORY 6 END****************************************

//****************************************RECEIPT FUNCTIONS START****************************************
/*
 * goToReciept()
 * This function switches the current UI to the Recipt UI and initializes the widgets on the UI.
 * Such as the final tour plan and distance, and souvenir receipt and total cost.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void studentpage::goToReceipt()
{
    QString start = *selectedCampuses.begin();
    recursiveCollegeSort(start);
    calcTotalDist();

    ui->stackedWidget->setCurrentWidget(ui->SortCollegeTour);

    for(int i = 0; i < sortedCampuses.count(); i++)
    {
        ui->sort_listWidget->addItem(sortedCampuses[i]);
    }

    //Total tour distance
    QString tourDistStr = QString::number(tourDist);
    ui->distanceNum_label->setText(tourDistStr);

    //Souvenirs
    QVector<QString> names;
    QVector<QString> quantities;
    while(!souvenirCart.empty())
    {
        names.push_back(souvenirCart.top().souvName);
        quantities.push_back(QString::number(souvenirCart.top().quantity));
        souvenirCart.pop();
    }

    //Souv Names
    ui->souvFinal_listView->setModel(new QStringListModel(QList<QString>::fromVector(names)));
    //Souv Quanitities
    ui->quantityFinal_listView->setModel(new QStringListModel(QList<QString>::fromVector(quantities)));

    while(!names.empty())
    {
        names.pop_back();
        quantities.pop_back();
    }
    //Total Souvenir Cost
    QString totalCostStr = QString::number(totalCost, 'f', 2);
    ui->totalNum_label->setText(totalCostStr);

    //Delete Cart Table
    database.deleteCart();
}

/*
 * on_finish_button_clicked
 * When the finish button on the receipt UI is clicked, all the changed data members are reset to default, and the current UI is switched to the main student page again.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void studentpage::on_finish_button_clicked()
{
     QMessageBox::information(this, "Loading...", "Tour Complete. Now moving to Main Student Screen.", QMessageBox::Ok, QMessageBox::NoButton);
    asuNum = 0;
    selectNum = 0;
    totalCost = 0;
    while(!sortedCampuses.empty())
    {
        sortedCampuses.pop_front();
    }
    ui->sort_listWidget->clear();
    sQry.clear();
    ui->stackedWidget->setCurrentWidget(ui->StudentSelect);
}
//****************************************RECEIPT FUNCTIONS END****************************************
