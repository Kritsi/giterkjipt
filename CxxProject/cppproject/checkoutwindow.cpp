#include "checkoutwindow.h"
#include "ui_checkoutwindow.h"
#include <iostream>
#include <string>
#include <QMessageBox>
#include "hotell.h"
#include "db.h"

Hotel h1;

CheckOutWindow::CheckOutWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckOutWindow)
{
    ui->setupUi(this);
    QPixmap pix("../sadcat2.jpg");
    pix = pix.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, pix);
    this->setPalette(palette);
}

CheckOutWindow::~CheckOutWindow()
{
    delete ui;
}

bool CheckOutWindow::checkAllInput(string itlf, string iname) {
    Customer c;
    bool tlf = c.checkTlfNr(itlf);
    bool name = c.checkName(iname);

    if(tlf && name) {
        return true;
    }

    if(!tlf) {
        ui->label_tlf_error->setText("Feil i tlf!");
    } else {
        ui->label_tlf_error->setText("");
    }

    if(!name) {
        ui->label_name_error->setText("Feil i navn!");
    } else {
        ui->label_name_error->setText("");
    }

    return true;
}

void CheckOutWindow::on_buttonBox_accepted()
{
    Database mydb;
    mydb.startDB();

    //Input
    int tlfNr = ui->inputFindTlf->text().toInt();
    string name = ui->inputFindName->text().toStdString();

    //QMessageBox msgBox;
    //string msg = "";

    bool correctInput = checkAllInput(to_string(tlfNr), name);

    if(correctInput) {
        int animalId = mydb.getAnimalId(tlfNr, name);
        mydb.removeAnimalFromCage(animalId);
        mydb.deleteAnimal(tlfNr, name);

        //msg += to_string(tlfNr) + " " + name + " is removed";

        //msgBox.setText(QString::fromStdString(msg));
        //msgBox.exec();

        //this->close();
    }
}

void CheckOutWindow::on_buttonBox_rejected()
{
    //this->close();
}
