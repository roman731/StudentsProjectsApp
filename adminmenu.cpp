#include "adminmenu.h"
#include "ui_adminmenu.h"


adminMenu::adminMenu(QWidget *parent, QString aIDp) :
    QDialog(parent),
    ui(new Ui::adminMenu)
{
    ui->setupUi(this);

    adminID = aIDp;
    adminProjects(adminID);

    //set default selection
    ui->listProjects->setCurrentRow(0);
}

adminMenu::~adminMenu()
{
    delete ui;
}

void adminMenu::on_buttonCreateProject_clicked()
{
    createProject();
    ui->listProjects->clear();
    adminProjects(adminID);
}

void adminMenu::adminProjects(QString aID)
{
    //query the DB
    QSqlQuery query = dbc->adminMenu_AutoQuery(aID);

    QStringList myList;
    while(query.next()) //get list of projects owned by the admin that's logged in
    {
        myList << query.value(0).toString();
    }
    QStringList stringList;
    for (int i = 0; i < myList.size(); ++i)
        stringList = QStringList() << stringList << myList.at(i).toLocal8Bit().constData();

    ui->listProjects->clear();
    ui->listProjects->addItems(stringList);
}

void adminMenu::createProject()
{
    QString name, description, teamSize, id;
    name = ui->lineName->text();
    description = ui->lineDescription->toPlainText();
    teamSize = ui->lineTeam->text();
    id = ui->lineID->text();

    dbc->adminMenu_createProjectQuery(id, name, description, teamSize, adminID);
}

void adminMenu::on_buttonSave_clicked()
{
    QString projectToEdit = ui->listProjects->currentItem()->text();

    QString newName = ui->editName->text();
    QString newDes = ui->editDes->toPlainText();
    QString newSize = ui->editSize->text();

    //get project ID of project that's selected
    QSqlQuery query = dbc->adminMenu_getProjectIDQuery(projectToEdit);
    QString projectID = query.value(0).toString();

    //save updates to DB
    dbc->adminMenu_updateDescriptionQuery(newName, newDes, newSize, projectID);

    //update UI
    adminProjects(adminID);
}

void adminMenu::displayProjectDetails()
{
    QString projectToDisplay = ui->listProjects->currentItem()->text();
    //get project details from selected project
    QSqlQuery query = dbc->adminMenu_displayProjectDetailsQuery(projectToDisplay);

    QString projectName = query.value(1).toString();
    QString projectDes = query.value(2).toString();
    QString projectSize = query.value(3).toString();

    ui->editName->setText(projectName);
    ui->editDes->setText(projectDes);
    ui->editSize->setText(projectSize);
}

void adminMenu::on_buttonBack_clicked()
{
    close();
}

void adminMenu::on_listProjects_clicked()
{
    displayProjectDetails();
}
