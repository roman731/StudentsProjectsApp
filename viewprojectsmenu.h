#ifndef VIEWPROJECTSMENU_H
#define VIEWPROJECTSMENU_H

#include <QDialog>
#include <QtDebug>
#include "databaseclass.h"

namespace Ui {
class viewProjectsMenu;
}

class viewProjectsMenu : public QDialog
{
    Q_OBJECT

public:
    explicit viewProjectsMenu(QWidget *parent, QString name);
    ~viewProjectsMenu();
    DatabaseClass *dbc = new DatabaseClass();
    QString student_id;
    void myProjects();


private slots:
    void on_buttonJoinProject_clicked();
    void on_buttonCancel_clicked();
    void on_buttonLeaveProject_clicked();

private:
    Ui::viewProjectsMenu *ui;
};

#endif // VIEWPROJECTSMENU_H
