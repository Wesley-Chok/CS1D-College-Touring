#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <QtSql>
#include <QVector>
#include <QQueue>

/** \class dbManager
 * Class for the database manager to interact with the database to get information.
 */
class dbManager
{
public:
    /** \fn Constructor
     * @param no formal parameters
     */
    dbManager();
    /** \fn Destructor
     * @param no formal parameters
     */
    ~dbManager();

    /** \fn loadCampusNamesOnly()
     * Using the "select XXX from" query funtion, the name of the college campuses are read in from the database into a QSqlQueryModel.
     * If a database error occurs, an error warning is printed to the console.
     * @param no formal parameters
     * @return QSqlQueryModel (pointer)
     */
    QSqlQueryModel *loadCampusNamesOnly();


    /** \fn loadRemainingCampusNamesOnly(QVector<QString> campuses)
     * Using the "select XXX from" query funtion, the name of the avaliable college campuses are read in from the database into a QSqlQueryModel.
     * The function excludes reading in the campuses from the passed in vector.
     * If a database error occurs, an error warning is printed to the console.
     * @param no formal parameters
     * @return QSqlQueryModel (pointer)
     */
    QSqlQueryModel *loadRemainingCampusNamesOnly(QVector<QString> campuses);


    /** \fn loadOtherCampusAndDist(QString campus)
     * Using the "select XXX from" query funtion and using the name of a single campus,
     * the names of the other campuses and their distance between them and the original campus are read in from the database into a QSqlQueryModel.
     * If a database error occurs, an error warning is printed to the console.
     * @param no formal parameters
     * @return QSqlQueryModel (pointer)
     */
    QSqlQueryModel *loadOtherCampusAndDist(QString campus);

    /** \fn loadCampusSouvenirs(QString campus)
     * Using the "select XXX from" query funtion, the souvenirs for a specified campus are read in from the database into a QSqlQueryModel.
     * If a database error occurs, an error warning is printed to the console.
     * @param no formal parameters
     * @return QSqlQueryModel (pointer)
     */
    QSqlQueryModel *loadCampusSouvenirs(QString campus);

    /** \fn loadSouvCart(QString sQry)
     * Using the "select XXX from" query funtion, the selected sovenirs are read in from the database into a QSqlQueryModel.
     * The query is an accumulator query that contains all the souvenirs the user has selected to add to an update quey using SQL code "UNION".
     * If a database error occurs, an error warning is printed to the console.
     * @param QString, sQry
     * @return QSqlQueryModel (pointer)
     */
    QSqlQueryModel* loadSouvCart(QString sQry);

    /** \fn createCart()
     * Creates a temporary table called cart in the SQL Database, and alters the table by adding a column called quantity for the quanity purchased.
     * @param no formal parameters
     * @return nothing returned
     */
    void createCart();

    /** \fn deleteCart()
     * This deletes the cart table in the SQL Database when the user has completed their shopping trip.
     * @param no formal parameters
     * @return nothing returned
     */
    void deleteCart();

    /** \fn updateCartQuantity(QString campus, QString souv, int quantity)
     * This function updates the changes of quantity to the cart table in the SQL Database.
     * @param QString, campus
     * @param QString, souv
     * @param int, quantity
     * @return nothing returned
     */
    void updateCartQuantity(QString campus, QString souv, int quantity);

    /** \fn GetTotalCost(QString campusIn, QString souvIn)
     * Using the "select XXX from" query funtion, gets the price of a souvenir .
     * If a database error occurs, an error warning is printed to the console.
     * @param QString, campusIn
     * @param QString, souvIn
     * @return int
     */
    double GetTotalCost(QString campusIn, QString souvIn);

    /** \fn GetDistBtwn(QString start, QString end)
     * Using the "select XXX from" query funtion, the distance between the 2 specified campuses.
     * If a database error occurs, an error warning is printed to the console.
     * @param QString, start
     * @param QString, end
     * @return double
     */
    double GetDistBtwn(QString start, QString end);

    /** \fn checkCampusName(QString campus)
     * Using the "select XXX from" query funtion, this function determines if the specified college is present in the database.
     * If a database error occurs, an error warning is printed to the console.
     * @param QString, campus
     * @return bool
     */
    bool checkCampusName(QString campus);

    /** \fn GetCampusCount(QString campus)
     * Using the "select XXX from" query funtion, the number of campuses in the database is counted.
     * If a database error occurs, an error warning is printed to the console.
     * @param QString, campus
     * @return int
     */
    int GetCampusCount(QString campus);

private:
    QSqlDatabase tourDB; /**< QSqlDatabase variable*/
};

#endif // DBMANAGER_H
