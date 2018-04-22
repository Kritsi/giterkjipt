#include "searchcustomerwindow.h"
#include "ui_searchcustomerwindow.h"
#include "userexistswindow.h"
#include "db.h"
#include <regex>

searchCustomerWindow::searchCustomerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchCustomerWindow)
{
    ui->setupUi(this);
}

searchCustomerWindow::~searchCustomerWindow()
{
    delete ui;
}

void searchCustomerWindow::setAnimalType(string type) {
    animalType = type;
}

void searchCustomerWindow::on_pushButton_clicked()
{
    Database mydb;

    string tlf = ui->inputTlf->text().toStdString();
    int tlfNr = 0;

    regex reg("^[0-9]{8}$");
    if(regex_match(tlf, reg)) {
        tlfNr = stoi(tlf);

        if(mydb.searchCustomer(tlfNr)) {
            userExistsWindow userExist;
            userExist.setTlfNr(tlfNr);
            userExist.setCusomerName();
            userExist.setAnimalType(animalType);
            userExist.setModal(true);
            userExist.exec();
            this->close();
        } else {
            ui->error_msg->setText("Kunden finnes ikke!");
        }
    } else {
        ui->error_msg->setText("Ikke gyldig tlfnr");
    }
}
