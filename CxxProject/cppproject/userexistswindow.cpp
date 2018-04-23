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

bool userExistsWindow::checkAllInput(string iname, string iage) {
    Animal a;
    bool name = a.checkName(iname);
    bool age = a.checkAge(iage);

    if(name && age) {
        return true;
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

void userExistsWindow::on_buttonBox_accepted()
{
    Database mydb;
    mydb.startDB();

    //Customer
    Customer c = mydb.createCustomer(tlfnr);

    //Animal
    Animal a;
    bool isFemale = ui->radioButton_5->isChecked();
    string name = ui->inputName->text().toStdString();
    int age = ui->inputAge->text().toInt();
    bool specialNeeds = ui->checkBox->checkState();

    //Check Input
    bool correctInput = false;//checkAllInput(name, to_string(age));

    if(correctInput) {
        mydb.insertCustomer(c.getFirstName(), c.getLastName(), tlfnr);
        mydb.insertAnimal(c, name, age, animalType, isFemale, specialNeeds);

        int animalId = mydb.getAnimalId(tlfnr, name);
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
