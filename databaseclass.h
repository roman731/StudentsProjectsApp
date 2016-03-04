#ifndef DATABASECLASS_H
#define DATABASECLASS_H

#include <QtDebug>
#include <QtSql>

class DatabaseClass
{
public:
    DatabaseClass();
    int mainWindow_StudentQuery(QString name, QString password);
    QString mainWindow_AdminQuery(QString name, QString password);
    QSqlQuery studentMenu_AutoQuery(QString name);
    void studentMenu_UpdateQuery(QString student_id, QString a1,QString a2,QString a3,QString a4,QString a5,QString a6,QString a7,QString a8,QString a9,QString a10,QString a11,QString a12,QString pa1,QString pa2,QString pa3,QString pa4,QString pa5,QString pa6,QString pa7,QString pa8,QString pa9,QString pa10,QString pa11,QString pa12);
    QSqlQuery adminMenu_AutoQuery(QString aID);
    QSqlQuery adminMenu_displayProjectDetails(QString projectToDisplay);
    void adminMenu_updateDescriptionQuery(QString newName, QString newDes, QString newSize, QString projectID);
    QSqlQuery adminMenu_getProjectIDQuery(QString projectToEdit);
    QSqlQuery adminMenu_displayProjectDetailsQuery(QString projectToDisplay);
    void adminMenu_createProjectQuery(QString id, QString name, QString description, QString teamSize, QString adminID);
    QStringList viewProjectsMenu_AutoQuery();
    void viewProjectsMenu_JoinProjectQuery();
    void viewProjectsMenu_JoinProjectQuery(QString projectToJoin, QString student_id);
    QStringList viewProjectsMenu_MyProjectsQuery(QString student_id);
    void viewProjectsMenu_LeaveProjectQuery(QString projectToLeave, QString student_id);
    QSqlDatabase myDB;

    void connectDB()
    {
        myDB=QSqlDatabase::addDatabase("QSQLITE");
        myDB.setDatabaseName(QDir::currentPath()+"/cupid.db");

        if(myDB.open()){
            qDebug()<< ("Database: Connection established...");
        }
        else{
            qDebug()<< ("Database: Database connection ERROR");
            qDebug()<< "The DB should be located in: " << QDir::currentPath();
        }
    }
    void closeDB()
    {
        QString connection = myDB.connectionName();
        myDB.close();
        myDB = QSqlDatabase();
        myDB.removeDatabase(connection);
       qDebug()<<"Connection closed.";
    }
};

#endif // DATABASECLASS_H
