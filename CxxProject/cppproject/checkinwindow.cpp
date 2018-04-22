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

void CheckInWindow::on_buttonBox_2_accepted()
{
    Database mydb;
    mydb.startDB();

    //Customer
    string firstname = ui->inputFirstname->text().toStdString();
    string lastname = ui->inputLastname->text().toStdString();
    string tlf = ui->inputTlf->text().toStdString();
    int tlfNr = ui->inputTlf->text().toInt();
    Customer c = Customer(firstname, lastname, tlf);

    //Animal
    bool isFemale = ui->radioButton_3->isChecked();
    string name = ui->inputName->text().toStdString();
    int age = ui->inputAge->text().toInt();
    bool specialNeeds = ui->checkBox->checkState();

    Animal a;
    if(animalType == "Cat") {
        a = Cat(c, 232, name, age, isFemale, specialNeeds);
    } else {
        a = Dog(c, 232, name, age, isFemale, specialNeeds);
    }

    bool freecage = false;
    if(animalType == "Cat") {
        if(mydb.checkFreeCatCages()) {
            freecage = true;
        }
    } else {
        if(mydb.checkFreeDogCages()) {
            freecage = true;
        }
    }

    if(freecage) {
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
    }
    this->close();
}

void CheckInWindow::on_buttonBox_2_rejected()
{
    this->close();
}
