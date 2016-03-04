#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "studentmenu.h"
#include "adminmenu.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connect to DB in main window constructor
    dbc->connectDB();

    //hide input for password textfield
    ui->textPass->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow()
{
    dbc->closeDB();
    delete dbc;
    delete ui;
}
//student attempts to login
void MainWindow::on_buttonLogin_clicked()
{
    //gets input from textfields and stores in variable
    name=ui->textName->text();
    password=ui->textPass->text();

    if(ui->radioStudent->isChecked())
    {
        //run DB query
        int returnValue = dbc->mainWindow_StudentQuery(name, password);

        //login successful if 1 is returned
        if (returnValue == 1)
        {
            ui->labelDB->setText("");
            studentMenu sm(0, name);
            sm.setModal(true);
            sm.exec();
            ui->textName->clear();
            ui->textPass->clear();
        }

        else if(returnValue != 1)
            ui->labelDB->setText("username and password incorrect");
    }
    //admin attempts to login
    else
    {
        QString returnValue = dbc->mainWindow_AdminQuery(name, password);

        //admin ID is returned is login successful, else -1 is returned
        if(returnValue != "-1")
        {
            ui->labelDB->setText("");

            adminMenu am(0,returnValue);
            am.setModal(true);
            am.exec();
            ui->textName->clear();
            ui->textPass->clear();
        }
        else
            ui->labelDB->setText("username and password incorrect");

    }
}
