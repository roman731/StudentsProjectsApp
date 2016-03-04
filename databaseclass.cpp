#include "databaseclass.h"


DatabaseClass::DatabaseClass()
{
}

int DatabaseClass::mainWindow_StudentQuery(QString name, QString password)
{
    QSqlQuery query;
    //checks textfields entered by student and compares it to DB
    if(query.exec("select * from students where name='" + name + "' and pass='" + password + "'"))
    {
        int i = 0;
        //checks how many users have this name and passoword.. should be 1
        while(query.next())
        {
            i++;
        }
        return i;
    }
    else
        qDebug()<<"An error has occured.";
    return 0;
}

QString DatabaseClass::mainWindow_AdminQuery(QString name, QString password)
{
    QSqlQuery query;
    //checks textfields entered by admin and compares it to DB
    if(query.exec("select * from admins where name='" + name + "' and pass='" + password + "'"))
    {
        QString aID;
        int i = 0;
        while(query.next())
        {
            aID = query.value(0).toString();
            i++;
        }
        if(i == 1)
        {
            return aID;
        }
    }
    else
        qDebug()<<"An error has occured.";

    return "-1";
}

QSqlQuery DatabaseClass::studentMenu_AutoQuery(QString name)
{
    QSqlQuery query;
    query.exec("select * from students where name='"+name+"'");
    query.next();
    return query;
}

void DatabaseClass::studentMenu_UpdateQuery(QString student_id, QString a1,QString a2,QString a3,QString a4,QString a5,QString a6,QString a7,QString a8,QString a9,QString a10,QString a11,QString a12,QString pa1,QString pa2,QString pa3,QString pa4,QString pa5,QString pa6,QString pa7,QString pa8,QString pa9,QString pa10,QString pa11,QString pa12)
{
    QSqlQuery query;
    query.prepare("update students set a1='"+a1+"', a2='"+a2+"', a3='"+a3+"', a4='"+a4+"', a5='"+a5+"', a6='"+a6+"', a7='"+a7+"', a8='"+a8+"', a9='"+a9+"', a10='"+a10+"', a11='"+a11+"', a12='"+a12+"',\
            pa1='"+pa1+"', pa2='"+pa2+"', pa3='"+pa3+"', pa4='"+pa4+"', pa5='"+pa5+"', pa6='"+pa6+"', pa7='"+pa7+"', pa8='"+pa8+"',pa9='"+pa9+"', pa10='"+pa10+"', pa11='"+pa11+"', pa12='"+pa12+"' WHERE sID="+student_id);
    query.exec();
}

QSqlQuery DatabaseClass::adminMenu_AutoQuery(QString aID)
{
    QSqlQuery query;
    query.exec("select projects.name from ownsProject,projects where ownsProject.pID=projects.pID AND ownsProject.aID="+aID);
    return query;
}

QSqlQuery DatabaseClass::adminMenu_displayProjectDetailsQuery(QString projectToDisplay)
{
    QSqlQuery query;
    query.exec("SELECT * FROM projects where name='"+projectToDisplay+"'");
    query.next();
    return query;
}

void DatabaseClass::adminMenu_updateDescriptionQuery(QString newName, QString newDes, QString newSize, QString projectID)
{
    QSqlQuery query;
    query.exec("UPDATE projects SET name='"+newName+"', description='"+newDes+"', teamSize="+newSize+" WHERE pID="+projectID);
}

QSqlQuery DatabaseClass::adminMenu_getProjectIDQuery(QString projectToEdit)
{
    QSqlQuery query;
    query.exec("SELECT * FROM projects where name='"+projectToEdit+"'");
    query.next();
    return query;
}

void DatabaseClass::adminMenu_createProjectQuery(QString id, QString name, QString description, QString teamSize, QString adminID)
{
    QSqlQuery query;

    query.exec("insert into projects (pID, name, description, teamSize) values ("+id+",'"+name+"', '"+description+"',"+teamSize+")" );

    query.exec("insert into ownsProject(aID, pID) values ("+adminID+","+id+")");

}

QStringList DatabaseClass::viewProjectsMenu_AutoQuery()
{
    QSqlQuery query;
    QStringList myList1;
    query.exec("select * from projects");
    while(query.next())
    {
        myList1 << query.value(1).toString();
    }
    QStringList stringList1;
    for (int i = 0; i < myList1.size(); ++i)
        stringList1 = QStringList() << stringList1 << myList1.at(i).toLocal8Bit().constData();

    return stringList1;
}

void DatabaseClass::viewProjectsMenu_JoinProjectQuery(QString projectToJoin, QString student_id)
{
    QSqlQuery query;

    //get project ID of project that's selected
    query.exec("SELECT * FROM projects where name='"+projectToJoin+"'");
    query.next();
    QString projectID = query.value(0).toString();
    query.exec("insert into stuInProject(sID, pID) values ("+student_id+", "+projectID+")");
}

QStringList DatabaseClass::viewProjectsMenu_MyProjectsQuery(QString student_id)
{
    QSqlQuery query;

    query.exec("select projects.name from stuInProject,projects where stuInProject.pID=projects.pID AND stuInProject.sID="+student_id);

    QStringList myList;
    while(query.next())
    {
        myList << query.value(0).toString();
    }
    QStringList stringList;
    for (int i = 0; i < myList.size(); ++i)
        stringList = QStringList() << stringList << myList.at(i).toLocal8Bit().constData();

    return stringList;
}

void DatabaseClass::viewProjectsMenu_LeaveProjectQuery(QString projectToLeave, QString student_id)
{
    QSqlQuery query;

    //get project ID of project that's selected
    query.exec("SELECT * FROM projects where name='"+projectToLeave+"'");
    query.next();
    QString projectID = query.value(0).toString();

    query.exec("delete FROM stuInProject where sID="+student_id+" AND pID="+projectID);
}
