#include "viewprojectsmenu.h"
#include "ui_viewprojectsmenu.h"

viewProjectsMenu::viewProjectsMenu(QWidget *parent, QString sid) :
    QDialog(parent),
    ui(new Ui::viewProjectsMenu)
{
    ui->setupUi(this);

    student_id = sid;

    //loads initial projects into viewbox
    myProjects();

    QStringList stringList1 = dbc->viewProjectsMenu_AutoQuery();

    ui->listProjects->addItems(stringList1);

    //sets default items to be selected
    ui->listProjects->setCurrentRow(0);
    ui->listmyProjects->setCurrentRow(0);
}

viewProjectsMenu::~viewProjectsMenu()
{
    delete ui;
}

void viewProjectsMenu::on_buttonJoinProject_clicked()
{
    QString projectToJoin = ui->listProjects->currentItem()->text();

    dbc->viewProjectsMenu_JoinProjectQuery(projectToJoin, student_id);

    //refresh the window
    myProjects();
}

void viewProjectsMenu::myProjects()
{
    QStringList stringList = dbc->viewProjectsMenu_MyProjectsQuery(student_id);

    ui->listmyProjects->clear();
    ui->listmyProjects->addItems(stringList);
}

void viewProjectsMenu::on_buttonCancel_clicked()
{
    close();
}

void viewProjectsMenu::on_buttonLeaveProject_clicked()
{
    QString projectToLeave = ui->listmyProjects->currentItem()->text();

    dbc->viewProjectsMenu_LeaveProjectQuery(projectToLeave, student_id);

    //refresh the window
    myProjects();
}
