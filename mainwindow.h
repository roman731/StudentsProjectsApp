#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtDebug>
#include "databaseclass.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    DatabaseClass *dbc = new DatabaseClass();
    QString name,password;


    QString getName() const { return name; }
    ~MainWindow();

private slots:
    void on_buttonLogin_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
