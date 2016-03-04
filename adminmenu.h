#ifndef ADMINMENU_H
#define ADMINMENU_H

#include <QDialog>
#include <QtDebug>
#include <QFileInfo>
#include "databaseclass.h"

namespace Ui {
class adminMenu;
}

class adminMenu : public QDialog
{
    Q_OBJECT

public:
    explicit adminMenu(QWidget *parent, QString aID);
    DatabaseClass *dbc = new DatabaseClass();
    QString adminID;
    void adminProjects(QString aID);
    void createProject();
    void displayProjectDetails();
    QSqlQuery query;
    ~adminMenu();

private slots:
    void on_buttonCreateProject_clicked();
    void on_buttonSave_clicked();
    void on_buttonBack_clicked();
    void on_listProjects_clicked();

private:
    Ui::adminMenu *ui;
};

#endif // ADMINMENU_H
