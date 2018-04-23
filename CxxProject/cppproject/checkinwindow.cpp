#include "checkinwindow.h"
#include "ui_checkinwindow.h"
#include "animal.h"
#include "cat.h"
#include "dog.h"
#include "person.h"
#include "kunde.h"
#include "db.h"
#include "textbox.h"
#include <iostream>
#include <string>
#include <QMessageBox>
#include <hotell.h>

using namespace std;

CheckInWindow::CheckInWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckInWindow)
{
    ui->setupUi(this);
}

CheckInWindow::~CheckInWindow()
{
    delete ui;
}

void CheckInWindow::setAnimalType(string type) {
    animalType = type;
}

bool CheckInWindow::checkAllInput(string ifirstname, string ilastname, string itlf, string iname, string iage) {
    Customer c;
    Animal a;
    bool fn = c.checkName(ifirstname);
    bool ln = c.checkName(ilastname);
    bool tlf = c.checkTlfNr(itlf);
    bool name = a.checkName(iname);
    bool age = a.checkAge(iage);

    if(fn && ln && tlf && name && age) {
        return true;
    }

    if(!fn) {
        ui->label_fn_error->setText("Feil i fornavn!");
    } else {
        ui->label_fn_error->setText("");
    }

    if(!ln) {
        ui->label_ln_error->setText("Feil i etternavn!");
    } else {
        ui->label_ln_error->setText("");
    }

    if(!tlf) {
        ui->label_tlf_error->setText("Feil i tlfnr!");
    } else {
        ui->label_tlf_error->setText("");
    }

    if(!name) {
        ui->label_name_error->setText("Feil i navn!");
    } else {
        ui->label_name_error->setText("");
    }

    if(!age) {
        ui->label_age_error->setText("Feil i alder!");
    } else {
        ui->label_age_error->setText("");
    }

    return false;
}

void CheckInWindow::on_buttonBox_2_accepted()
{
    Database mydb;
    mydb.startDB();

    //Customer
    string firstname = ui->inputFirstname->text().toStdString();
    string lastname = ui->inputLastname->text().toStdString();
    int tlfNr = ui->inputTlf->text().toInt();
    Customer c = Customer(firstname, lastname, to_string(tlfNr));

    //Animal
    bool isFemale = ui->radioButton_3->isChecked();
    string name = ui->inputName->text().toStdString();
    int age = ui->inputAge->text().toInt();
    bool specialNeeds = ui->checkBox->checkState();
    Animal a;

    //Check input
    bool correctInput = checkAllInput(firstname, lastname, to_string(tlfNr), name, to_string(age));

    if(correctInput) {
        mydb.insertCustomer(firstname, lastname, tlfNr);
        mydb.insertAnimal(c, name, age, animalType, isFemale, specialNeeds);

        int animalId = mydb.getAnimalId(tlfNr, name);
        if(animalType == "Cat") {
            mydb.setCatInCage(animalId);
        } else {
            mydb.setDogInCage(animalId);
        }

        if(specialNeeds) {
            textBox textbox;
            textbox.setCustomer(c);
            textbox.setAnimalName(name);
            textbox.setModal(true);
            textbox.exec();
        }
        this->close();
    }
}

void CheckInWindow::on_buttonBox_2_rejected()
{
    this->close();
}
