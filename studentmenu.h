#ifndef STUDENTMENU_H
#define STUDENTMENU_H

#include <QDialog>
#include <QtDebug>
#include "databaseclass.h"

namespace Ui {
class studentMenu;
}

class studentMenu : public QDialog
{
    Q_OBJECT

public:
    explicit studentMenu(QWidget *parent, QString name);
    ~studentMenu();
    DatabaseClass *dbc = new DatabaseClass();
    QString student_id, student_name;
    QString a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,pa1,pa2,pa3,pa4,pa5,pa6,pa7,pa8,pa9,pa10,pa11,pa12;

private slots:
    void on_buttonViewProjects_clicked();
    void on_buttonUpdate_clicked();

private:
    Ui::studentMenu *ui;
};

#endif // STUDENTMENU_H
