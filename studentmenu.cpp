#include "studentmenu.h"
#include "ui_studentmenu.h"
#include "viewprojectsmenu.h"
#include "mainwindow.h"
#include <QDialog>

studentMenu::studentMenu(QWidget *parent, QString name) :
    QDialog(parent),
    ui(new Ui::studentMenu)

{ 
    ui->setupUi(this);

    //gets id, name and attributes of found student (student should be in there since login was successful)
    QSqlQuery query = dbc->studentMenu_AutoQuery(name);
    student_id = query.value(0).toString();
    student_name = query.value(1).toString();

    ui->textName->setText(student_name);
    ui->textNumber->setText(student_id);

    //updates UI
    ui->a1->setText(query.value(3).toString());
    ui->a2->setText(query.value(4).toString());
    ui->a3->setText(query.value(5).toString());
    ui->a4->setText(query.value(6).toString());

    ui->a5->setText(query.value(7).toString());
    ui->a6->setText(query.value(8).toString());
    ui->a7->setText(query.value(9).toString());
    ui->a8->setText(query.value(10).toString());

    ui->a9->setText(query.value(11).toString());
    ui->a10->setText(query.value(12).toString());
    ui->a11->setText(query.value(13).toString());
    ui->a12->setText(query.value(14).toString());

    ui->pa1->setText(query.value(15).toString());
    ui->pa2->setText(query.value(16).toString());
    ui->pa3->setText(query.value(17).toString());
    ui->pa4->setText(query.value(18).toString());

    ui->pa5->setText(query.value(19).toString());
    ui->pa6->setText(query.value(20).toString());
    ui->pa7->setText(query.value(21).toString());
    ui->pa8->setText(query.value(22).toString());

    ui->pa9->setText(query.value(23).toString());
    ui->pa10->setText(query.value(24).toString());
    ui->pa11->setText(query.value(25).toString());
    ui->pa12->setText(query.value(26).toString());
}

studentMenu::~studentMenu()
{
    delete ui;
}

void studentMenu::on_buttonViewProjects_clicked()
{
    viewProjectsMenu vpm(0,student_id);
    vpm.setModal(true);
    vpm.exec();
}

void studentMenu::on_buttonUpdate_clicked()
{
    //gets text from UI for query
    a1=ui->a1->text(); a2=ui->a2->text(); a3=ui->a3->text(); a4=ui->a4->text();
    a5=ui->a5->text(); a6=ui->a6->text(); a7=ui->a7->text(); a8=ui->a8->text();
    a9=ui->a9->text(); a10=ui->a10->text(); a11=ui->a11->text(); a12=ui->a12->text();

    pa1=ui->pa1->text(); pa2=ui->pa2->text(); pa3=ui->pa3->text(); pa4=ui->pa4->text();
    pa5=ui->pa5->text(); pa6=ui->pa6->text(); pa7=ui->pa7->text(); pa8=ui->pa8->text();
    pa9=ui->pa9->text(); pa10=ui->pa10->text(); pa11=ui->pa11->text(); pa12=ui->pa12->text();

    dbc->studentMenu_UpdateQuery(student_id, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, pa1, pa2, pa3, pa4, pa5, pa6, pa7, pa8, pa9, pa10, pa11, pa12);
}
