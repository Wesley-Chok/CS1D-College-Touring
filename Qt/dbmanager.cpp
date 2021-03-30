#include "dbmanager.h"

/*
 * Constructor
 * IN: no formal parameters
 */
dbManager::dbManager()
{
    //Connects the database to the project
    tourDB = QSqlDatabase::addDatabase("QSQLITE");
    tourDB.setDatabaseName("C:/Users/shado/Desktop/Class Project #1/Information_Database.db");
    if(!tourDB.open())
    {
        qDebug() << "\nError Opening Database\n";
    }

}

/*
 * Destructor
 * IN: no formal parameters
 */
dbManager::~dbManager() {}

/*
 * loadCampusNamesOnly()
 * Using the "select XXX from" query funtion, the name of the college campuses are read in from the database into a QSqlQueryModel.
 * If a database error occurs, an error warning is printed to the console.
 * IN: no formal parameters
 * OUT: QSqlQueryModel (pointer)
 */
QSqlQueryModel* dbManager::loadCampusNamesOnly()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QString sQry = "select distStart as \"Campuses\" from Distances group by distStart;";
    QSqlQuery qry;
    qry.prepare(sQry);

    if(!qry.exec())
    {
        qDebug() << "\nError Loading Campuses\n";
    }

    model->setQuery(qry);
    return model;
}

/*
 * loadRemainingCampusNamesOnly(QVector<QString> campuses)
 * Using the "select XXX from" query funtion, the name of the avaliable college campuses are read in from the database into a QSqlQueryModel.
 * The function excludes reading in the campuses from the passed in vector.
 * If a database error occurs, an error warning is printed to the console.
 * IN: no formal parameters
 * OUT: QSqlQueryModel (pointer)
 */
QSqlQueryModel* dbManager::loadRemainingCampusNamesOnly(QVector<QString> campuses)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QString* p = campuses.begin();
    QString sQry = "select distStart as \"Campuses\" from Distances where not distStart = '" +*p+ "'";
    p++;
    while (p != campuses.end())
    {
        sQry += " and not distStart = '" +*p+ "'";
        p++;
    }
    sQry += " group by distStart;";
    QSqlQuery qry;
    qry.prepare(sQry);

    if(!qry.exec())
    {
        qDebug() << "\nError Loading Campuses\n";
    }

    model->setQuery(qry);
    return model;
}

/*
 * loadOtherCampusAndDist(QString campus)
 * Using the "select XXX from" query funtion and using the name of a single campus,
 * the names of the other campuses and their distance between them and the original campus are read in from the database into a QSqlQueryModel.
 * If a database error occurs, an error warning is printed to the console.
 * IN: no formal parameters
 * OUT: QSqlQueryModel (pointer)
 */
QSqlQueryModel* dbManager::loadOtherCampusAndDist(QString campus)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QString sQry = "SELECT distEnd as 'Campuses', distBtwn as 'Distance(mi)' FROM Distances WHERE distStart='" + campus + "';";
    QSqlQuery qry;
    qry.prepare(sQry);

    if(!qry.exec())
    {
        qDebug() << "\nError Loading Campuses\n";
    }

    model->setQuery(qry);
    return model;
}

/*
 * loadCampusSouvenirs(QString campus)
 * Using the "select XXX from" query funtion, the souvenirs for a specified campus are read in from the database into a QSqlQueryModel.
 * If a database error occurs, an error warning is printed to the console.
 * IN: no formal parameters
 * OUT: QSqlQueryModel (pointer)
 */
QSqlQueryModel* dbManager::loadCampusSouvenirs(QString campus)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QString sQry = "select souvTrad as 'Souvenirs', souvCost as 'Cost($)' from Souvenirs where souvCollege = '" +campus+ "';";
    qDebug() << sQry;
    QSqlQuery qry;
    qry.prepare(sQry);

    if(!qry.exec())
    {
        qDebug() << "\nError Loading Campuses\n";
    }

    model->setQuery(qry);
    return model;
}

/*
 * createCart()
 * Creates a temporary table called cart in the SQL Database, and alters the table by adding a column called quantity for the quanity purchased.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void dbManager::createCart()
{
    //cartQry - temporary table
    QSqlQuery cartQry;
    cartQry.prepare("create table Cart as SELECT * from Souvenirs;");

    if(!cartQry.exec())
    {
        qDebug() << "\nError Creating Cart\n";
    }
    cartQry.prepare("ALTER table Cart add quantity real default 0;");
    if(!cartQry.exec())
    {
        qDebug() << "\nError Creating Quanitity Column\n";
    }
}

/*
 * deleteCart()
 * This deletes the cart table in the SQL Database when the user has completed their shopping trip.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void dbManager::deleteCart()
{
    //cartQry - temporary table
    QSqlQuery cartQry;
    cartQry.prepare("drop table Cart;");

    if(!cartQry.exec())
    {
        qDebug() << "\nError dropping Cart\n";
    }
}

/*
 * updateCartQuantity(QString campus, QString souv, int quantity)
 * This function updates the changes of quantity to the cart table in the SQL Database.
 * IN: QString, campus
 * IN: QString, souv
 * IN: int, quantity
 * OUT: nothing returned
 */
void dbManager::updateCartQuantity(QString campus, QString souv, int quant)
{
    //Update quantity
    QSqlQuery updateQry;
    QString uQry = "UPDATE Cart SET quantity = quantity+" +QString::number(quant)+ " WHERE souvCollege = '" +campus+ "' and souvTrad = '" +souv+ "';";
    updateQry.prepare(uQry);

    if(!updateQry.exec())
    {
        qDebug() << "\nError updating Cart\n";
    }
}

/*
 * loadSouvCart(QString sQry)
 * Using the "select XXX from" query funtion, the selected sovenirs are read in from the database into a QSqlQueryModel.
 * The query is an accumulator query that contains all the souvenirs the user has selected to add to an update quey using SQL code "UNION".
 * If a database error occurs, an error warning is printed to the console.
 * IN: QString, sQry
 * OUT: QSqlQueryModel (pointer)
 */
QSqlQueryModel* dbManager::loadSouvCart(QString sQry)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare(sQry);

    if(!qry.exec())
    {
        qDebug() << "\nError Loading Souvenirs\n";
    }

    model->setQuery(qry);
    return model;
}

/*
 * GetTotalCost(QString campusIn, QString souvIn)
 * Using the "select XXX from" query funtion, gets the price of a souvenir .
 * If a database error occurs, an error warning is printed to the console.
 * IN: QString, campusIn
 * IN: QString, souvIn
 * OUT: int
 */
double dbManager::GetTotalCost(QString campusIn, QString souvIn)
{
    double total = 0.0;

    QString sQry = "select souvCost as 'Cost' "
                    "from Souvenirs where souvCollege = '" +campusIn+ "' and souvTrad = '" +souvIn+ "'";
    QSqlQuery qry;
    qry.prepare(sQry);
    qry.exec();

    if(qry.next())
    {
        total = qry.value(0).toDouble();
    }
    return total;
}

/*
 * GetDistBtwn(QString start, QString end)
 * Using the "select XXX from" query funtion, the distance between the 2 specified campuses.
 * If a database error occurs, an error warning is printed to the console.
 * IN: QString, start
 * IN: QString, end
 * OUT: double
 */
double dbManager::GetDistBtwn(QString start, QString end)
{
    double distBtwn = 0;
    QString sQry = "select distBtwn from Distances where distStart = '" +start+ "' and distEnd = '" +end+ "';";

    QSqlQuery qry;
    qry.prepare(sQry);
    qry.exec();

    if(qry.next())
    {
        distBtwn = qry.value(0).toDouble();
    }

    return distBtwn;
}

/*
 * checkCampusName(QString campus)
 * Using the "select XXX from" query funtion, this function determines if the specified college is present in the database.
 * If a database error occurs, an error warning is printed to the console.
 * IN: QString, campus
 * OUT: bool
 */
bool dbManager::checkCampusName(QString campus)
{
    bool execute = false;
    QSqlQuery qry;
    qry.prepare("SELECT * from Distances where distStart = '" +campus+ "'");

    if(qry.exec())
    {
        execute = qry.next();
    }
    return execute;
}

/*
 * GetCampusCount(QString campus)
 * Using the "select XXX from" query funtion, the number of campuses in the database is counted.
 * If a database error occurs, an error warning is printed to the console.
 * IN: QString, campus
 * OUT: int
 */
int dbManager::GetCampusCount(QString campus)
{
    int campusCount = 0;
    QString sQry = "select count(distStart) from Distances where distStart = '" +campus+ "';";

    QSqlQuery qry;
    qry.prepare(sQry);
    qry.exec();

    if(qry.next())
    {
        campusCount= qry.value(0).toInt();
    }

    return campusCount + 1;
}
