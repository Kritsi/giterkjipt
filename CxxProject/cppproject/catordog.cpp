#include "catordog.h"
#include "ui_catordog.h"
#include "user.h"
#include "db.h"
#include <QMessageBox>

CatOrDog::CatOrDog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CatOrDog)
{
    ui->setupUi(this);
}

CatOrDog::~CatOrDog()
{
    delete ui;
}

void CatOrDog::on_btnCat_clicked()
{
    Database mydb;
    string msg = "";

    if(mydb.checkFreeCatCages()) {
        user users;
        users.setAnimalType("Cat");
        users.setModal(true);
        users.exec();
        this->close();
    } else {
        msg += "Ingen ledig katteplasser!";
        ui->label_error->setText(QString::fromStdString(msg));
    }
}

void CatOrDog::on_btnDog_clicked()
{
    Database mydb;
    string msg = "";

    if(mydb.checkFreeDogCages()) {
        user users;
        users.setAnimalType("Dog");
        users.setModal(true);
        users.exec();
        this->close();
    } else {
        msg += "Ingen ledig hundeplasser!";
        ui->label_error->setText(QString::fromStdString(msg));
    }
}
