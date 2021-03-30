#include "adminpage.h"
#include "QDebug"
#include <iostream>
#include <string>
#include <QFileDialog>
#include <fstream>

/* Constructor
 * IN: no formal parameters
 */
adminpage::adminpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminpage)
{
    ui->setupUi(this);
    // Sets default page to be the home page
    ui->stackedWidget->setCurrentWidget(ui->adminHomePage);
    setupConnections();

    showSouvenirComboBoxDeletePage(database_.loadCampusNamesOnly());
    showCampusComboBoxAddPage(database_.loadCampusNamesOnly());
    showchangeSouvenirPageCampusNameComboBox(database_.loadCampusNamesOnly());

}

/*
 * Destructor
 * IN: no formal parameters
 */
adminpage::~adminpage()
{
    delete ui;
}

/*
 * setupConnections()
 * Sets up the button connections between the different widget pages for the adminpage
 * IN: no formal parameters
 * OUT: nothing returned
 */
void adminpage::setupConnections()
{
    connect(ui->addSouvenirBtn, &QPushButton::clicked, this, &adminpage::changeToSouvenirPage);
    connect(ui->addSouvenirPageBackBtn, &QPushButton::clicked, this, &adminpage::changeToAdminHomePage);
    connect(ui->changeSouvenirPriceBtn, &QPushButton::click, this, &adminpage::changeToSouvenirPricePage);
    connect(ui->changeSouvPriceBackBtn, &QPushButton::click, this, &adminpage::changeToAdminHomePage);
    connect(ui->deleteSouvenirBtn, &QPushButton::click, this, &adminpage::changeToSouvenirDeletePage);
    connect(ui->deletePageBackBtn, &QPushButton::click, this, &adminpage::changeToAdminHomePage);
}


/*
 * changeToAdminHomePage()
 * This function switches the ui widgets. For this one, it changes to the Admin home page.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void adminpage::changeToAdminHomePage()
{
    ui->stackedWidget->setCurrentWidget(ui->adminHomePage);
}

/*
 * changeToSouvenirPage()
 * This function switches the ui widgets. For this one, it changes to the changes the souvenir page.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void adminpage::changeToSouvenirPage()
{
    ui->stackedWidget->setCurrentWidget(ui->addSouvenirPage);
}

/*
 * changeToSouvenirPricePage()
 * This function switches the ui widgets. For this one, it changes to the Souvenir price page.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void adminpage::changeToSouvenirPricePage()
{
    ui->stackedWidget->setCurrentWidget(ui->changeSouvenirPricePage);
}


/*
 * changeToSouvenirDeletePage()
 * This function switches the ui widgets. For this one, it changes to the Delete souvenir page.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void adminpage::changeToSouvenirDeletePage()
{
    ui->stackedWidget->setCurrentWidget(ui->deleteSouvenirPage);


}

/*
 * on_viewSouvenirBtn_clicked()
 * This function allows the user to the Souvenir database in its entirety through the tableView widget.
 * The QSqlQueryModel pointer is used select which database to be output using the prepare function.
 * IN: no formal
 * OUT: nothing returned
 */
void adminpage::on_viewSouvenirBtn_clicked()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QSqlQuery* view = new QSqlQuery();

    view->prepare("SELECT * FROM Souvenirs ORDER by souvCollege ASC");

    view->exec();
    model->setQuery(*view);

    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0, 120);
}

/*
 * on_viewDistancesBtn_clicked()
 * This function allows the user to the Distance database in its entirety through the tableView widget.
 * The QSqlQueryModel pointer is used select which database to be output using the prepare function.
 * IN: no formal
 * OUT: nothing returned
 */
void adminpage::on_viewDistancesBtn_clicked()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QSqlQuery* view = new QSqlQuery();

    view->prepare("SELECT * FROM Distances ORDER by distStart ASC");

    view->exec();
    model->setQuery(*view);

    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0, 120);
}

/*
 * showSouvenirComboBoxDeletePage()
 * This function switches the ui widgets. For this one, it changes to the Delete souvenir page.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void adminpage::showSouvenirComboBoxDeletePage(QSqlQueryModel *model)
{
    ui->deletePageComboBox->setModel(model);
}

/*
 * showCampusComboBoxAddPage(QSqlQueryModel * model)
 * This function creates values for the combo box. The setModel is created by using the loadCampusNamesOnly function in dbmanager.cpp
 * IN: QSqlQueryModel, model (passed as a pointer)
 * OUT: nothing returned
 */
void adminpage::showCampusComboBoxAddPage(QSqlQueryModel * model)
{
    ui->addSouvenirPageCampusNameComboBox->setModel(model);
}

//*********************************************START OF STORY POINT 7A******************************************************//

/*
 * on_addCampusThroughInputFile_clicked()
 * This function allows the user to go to the add Campus and Souvenir page.
 * To accomodate for the values in the combo box on the Campus and Souvenir page, it calls the loadSouvenirsOnly() through showSouvenirsOnly().
 * IN: no formal
 * OUT: nothing returned
 */
void adminpage::on_addCampusThroughInputFile_clicked()
{
    std::string startDist;
    std::string endDist;
    double numDist;

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"/Desktop", tr("Txt Files (*.txt)"));     /// user picks the txt file to choose from
    QFile file(fileName);

    std::ifstream inFile;
    inFile.open(fileName.toStdString());

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(this,QObject::tr("System Message"),tr("File is invalid! Cannot be found."),QMessageBox::Ok);
        return;
    }
    else
    {
         while(inFile) {
            getline(inFile, startDist);
            getline(inFile, endDist);
            inFile >> numDist;
            inFile.ignore(10000,'\n');

            QString start_dist = QString::fromStdString(startDist);
            QString end_dist = QString::fromStdString(endDist);

            QSqlQuery query;
            query.prepare("INSERT INTO Distances(distStart, distEnd, distBtwn)"
                          " VALUES (:start_dist, :end_dist, :addDist)");
            query.bindValue(":start_dist", start_dist);
            query.bindValue(":end_dist", end_dist);
            query.bindValue(":addDist", numDist);

            if(query.exec())
            {
                qDebug() << "Query executed !";
            }
            else
            {
                qDebug() << "Query UNABLE to execute!";
                QMessageBox::information(this,QObject::tr("System Message"),tr("Failure to input the desired campus as it already exists!"),QMessageBox::Ok);
                break;
            }
        }
         QMessageBox::information(this,QObject::tr("System Message"),tr("Campus distances have been added!"),QMessageBox::Ok);
    }
}

/*
 *  on_addSouvenirThroughInputFile_clicked()
 * This function allows the user to go to the add specific Souvenirs entries.
 * When clicked, the button directs the user to their documents, where they can select the appropriate .txt to be read in.
 * To read the file, the QFileDialog and fstream includes are used.
 * std::string variables are converted to QString through the fromStdString function.
 * Finally, a QSqlQuery variable is used to insert the values and bind the values into the database.
 * IN: no formal
 * OUT: nothing returned
 */
void adminpage::on_addSouvenirThroughInputFile_clicked()
{
    std::string campusName;
    std::string souvenirName;
    double souvenirPrice;

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"/Desktop", tr("Txt Files (*.txt)"));     /// user picks the txt file to choose from
    QFile file(fileName);

    std::ifstream inFile;
    inFile.open(fileName.toStdString());

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(this,QObject::tr("System Message"),tr("File is invalid! Cannot be found."),QMessageBox::Ok);
        return;
    }
    else
    {
         while(inFile) {
            getline(inFile, campusName);
            getline(inFile, souvenirName);
            inFile >> souvenirPrice;
            inFile.ignore(10000, '\n');

            QString souv_College = QString::fromStdString(campusName);
            QString souvTrad = QString::fromStdString(souvenirName);

            QSqlQuery query;
            query.prepare("INSERT INTO Souvenirs(souvCollege, souvTrad, souvCost)"
                          " VALUES (:souv_College, :souvTrad, :souvCost)");
            query.bindValue(":souv_College", souv_College);
            query.bindValue(":souvTrad", souvTrad);
            query.bindValue(":souvCost", souvenirPrice);

            if(query.exec())
            {
                qDebug() << "Query executed !";
            }
            else
            {
                qDebug() << "Query UNABLE to execute!";
                QMessageBox::information(this,QObject::tr("System Message"),tr("Failure to input the desired souvenir as it already exists!"),QMessageBox::Ok);
                break;
            }
        }
         QMessageBox::information(this,QObject::tr("System Message"),tr("Campus souvenirs have been added!"),QMessageBox::Ok);
    }
}
//*********************************************END OF STORY POINT 7A******************************************************//



//*********************************************START OF STORY POINT 7B******************************************************//
/*
 * on_changeSouvPriceBackBtn_clicked()
 * This function allows the user to go back to the main admin page. It sets the current widget to the main admin page UI.
 * IN: no formal
 * OUT: nothing returned
 */
void adminpage::on_changeSouvPriceBackBtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->adminHomePage);
}

/*
 * showChangeSouvenirPageCampusNameComboBox(QSqlQueryModel * model)
 * This function creates calues for the combo box. The setModel is created using the loadCampusNamesOnly function in dbmanager.cpp
 * IN: QSqlQueryModel, model (passed as a pointer)
 * OUT: nothing returned
 */
void adminpage::showchangeSouvenirPageCampusNameComboBox(QSqlQueryModel * model)
{
    ui->changeSouvenirPageCampusNameComboBox->setModel(model);
}


/*
 * on_changeSouvenirPriceBtn_clicked()
 * This function allows the user to go back to the Souvenir price page. It sets the current widget to the changeSouvenirPricePage.
 * IN: no formal
 * OUT: nothing returned
 */
void adminpage::on_changeSouvenirPriceBtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->changeSouvenirPricePage);
}


/*
 * on_updateSouvenirPriceBtn_clicked()
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
void adminpage::on_updateSouvenirPriceBtn_clicked()
{
    QString souvCampus;
    QString souvTrad;
    QString souvPrice;

    souvCampus = ui->changeSouvenirPageCampusNameComboBox->currentText();
    souvTrad = ui->souvPriceChangeName_line->text();
    souvPrice = ui->souvChangePrice_line->text();

    bool check = false;

    for(int i = 0; i < souvPrice.length(); i++)
    {
        if(souvPrice[i] != '0' && souvPrice[i] != '1' && souvPrice[i] != '2' && souvPrice[i] != '3'
                && souvPrice[i] != '4' && souvPrice[i] != '5'
                && souvPrice[i] != '6' && souvPrice[i] != '7'
                && souvPrice[i] != '8' && souvPrice[i] != '9' && souvPrice[i] != '.')
        {
            check = true;
            break;
        }
    }

    if(check == true)
    {
        QMessageBox::about(this, "Invalid Input", "There was an invalid input. Please use only Numerals(0-9) and the . ");
        ui->stackedWidget->setCurrentWidget(ui->adminHomePage);
        return;
    }

    QSqlQuery qry;
    qry.prepare("UPDATE Souvenirs SET souvCollege = '"+souvCampus+"', souvTrad = '"+souvTrad+"' ,souvCost = '"+souvPrice+"' WHERE souvTrad = '"+souvTrad+"' AND souvCollege = '"+souvCampus+"' ");
    qry.exec();

    if(qry.numRowsAffected() == 0)
    {
        QMessageBox::critical(this, tr("error::"), qry.lastError().text());
    }
    else
    {
        QMessageBox::about(this, tr("Edit"), tr("Updated"));
    }

    ui->stackedWidget->setCurrentWidget(ui->adminHomePage);
}
//*********************************************END OF STORY POINT 7B******************************************************//




//*********************************************START OF STORY POINT 7C******************************************************//
/*
 * on_addSouvenirBtn_clicked()
 * This function allows the user to go to the add Souvenir page. The widget will be then set to addSouvenirPage widget.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void adminpage::on_addSouvenirBtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->addSouvenirPage);
}


/*
 * on_createSouvenirBtn_clicked()
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
 * IN: no formal parameters
 * OUT: nothing returned
 */
void adminpage::on_createSouvenirBtn_clicked()
{

    QSqlQuery data;
    QSqlQuery dataOne;
    QSqlQuery dataTwo;

    QString campusName = ui->addSouvenirPageCampusNameComboBox->currentText();
    QString souvName = ui->souvName_line->text();
    QString souvPrice = ui->souvPrice_line->text();

    bool check = false;

    for(int i = 0; i < souvPrice.length(); i++)
    {
        if(souvPrice[i] != '0' && souvPrice[i] != '1' && souvPrice[i] != '2' && souvPrice[i] != '3'
                && souvPrice[i] != '4' && souvPrice[i] != '5'
                && souvPrice[i] != '6' && souvPrice[i] != '7'
                && souvPrice[i] != '8' && souvPrice[i] != '9' && souvPrice[i] != '.')
        {
            check = true;
            break;
        }
    }

    if(check == true)
    {
        QMessageBox::about(this, "Invalid Input", "There was an invalid input. Please use only Numerals(0-9) and the . ");
        ui->stackedWidget->setCurrentWidget(ui->adminHomePage);
        return;
    }

    data.prepare("INSERT INTO Souvenirs (souvCollege, souvTrad, souvCost) VALUES ('"+campusName+"', '"+souvName+"', '"+souvPrice+"')");

    if(!data.exec())
    {
        QMessageBox::about(this, "Error", "Database not found double check path to database!");

    }
    else
    {
        QMessageBox::about(this, "", "The item was added. Double check if an error occured.");
    }

    ui->stackedWidget->setCurrentWidget(ui->adminHomePage);
}
//*********************************************END OF STORY POINT 7C******************************************************//



//*********************************************START OF STORY POINT 7D******************************************************//



/*
 * on_deleteSouvenirBtn_clicked()
 * This function switches to the delete page once pressed. The stacked widget ultimately changes to the delete souvenir page
 * IN: no formal parameters
 * OUT: nothing returned
 */
void adminpage::on_deleteSouvenirBtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->deleteSouvenirPage);
}

/*
 * on_deletePageBackBtn_clicked()
 * This function allows the user to go back to the admin home page. The stacked widget ultimately changes back to the admin home page.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void adminpage::on_deletePageBackBtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->adminHomePage);
}

/*
 * on_deleteSouvenirBtn_clicked()
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
 * IN: no formal parameters
 * OUT: nothing returned
 */
void adminpage::on_deleteSouvenirConfirmBtn_clicked()
{
    int souvCount = 0;
    int afterSouvCount = 0;

    QString nameCampus = ui->deletePageComboBox->currentText();
    QString nameSouv = ui->deletePageSouvenirName_line->text();

    QSqlQuery data;
    QSqlQuery dataOne;
    QSqlQuery dataTwo;
    QSqlQuery qry;

    souvCount = data.prepare("SELECT COUNT(souvCollege) FROM Souvenirs");
    data.exec();

    if(data.next())
    {
        souvCount = data.value(0).toInt();
    }

    qry.prepare("DELETE FROM Souvenirs WHERE souvCollege = '"+nameCampus+"' AND souvTrad = '"+nameSouv+"'");
    qry.exec();
    dataOne.exec();

    afterSouvCount = dataTwo.prepare("SELECT COUNT(souvCollege) FROM Souvenirs");
    dataTwo.exec();

    if(dataTwo.next())
    {
        afterSouvCount = dataTwo.value(0).toInt();
    }

    if(souvCount == afterSouvCount)
    {
        QMessageBox::about(this, "Error", "Value not found double check path to database!");
    }
    else
    {
        QMessageBox::about(this, "", "The item was deleted. Double check if an error occured");

        ui->stackedWidget->setCurrentWidget(ui->adminHomePage);
    }
}

//*********************************************END OF STORY POINT 7D******************************************************//
