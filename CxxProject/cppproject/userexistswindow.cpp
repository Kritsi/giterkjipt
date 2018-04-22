#include "userexistswindow.h"
#include "ui_userexistswindow.h"
#include "animal.h"
#include "cat.h"
#include "dog.h"
#include "kunde.h"
#include "hotell.h"
#include "db.h"
#include "textbox.h"
#include <iostream>
#include <QMessageBox>

using namespace std;

userExistsWindow::userExistsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userExistsWindow)
{
    ui->setupUi(this);

}

userExistsWindow::~userExistsWindow()
{
    delete ui;
}

void userExistsWindow::setTlfNr(int tlf) {
    tlfnr = tlf;
}

void userExistsWindow::setCusomerName() {
    Database mydb;
    mydb.startDB();

    Customer c = mydb.createCustomer(tlfnr);

    string cName = c.getFirstName() + " " + c.getLastName();

    ui->nameCustomer->setText(QString::fromStdString(cName));
}

void userExistsWindow::setAnimalType(string type) {
    animalType = type;
}

void userExistsWindow::on_buttonBox_accepted()
{
    //Customer
    int tlfNr = tlfnr;

    //Animal
    bool isFemale = ui->radioButton_5->isChecked();

    string name = ui->inputName->text().toStdString();
    int age = ui->inputAge->text().toInt();
    bool specialNeeds = ui->checkBox->checkState();

    Database mydb;
    Customer c = mydb.createCustomer(tlfNr);
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
        mydb.insertCustomer(c.getFirstName(), c.getLastName(), stoi(c.getTlfNr()));
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
}
