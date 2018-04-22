#include "user.h"
#include "ui_user.h"
#include "checkinwindow.h"
#include "userexistswindow.h"
#include "searchcustomerwindow.h"

user::user(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user)
{
    ui->setupUi(this);
}

user::~user()
{
    delete ui;
}

void user::setAnimalType(string type) {
    animalType = type;
}

void user::on_pushButton_clicked()
{

}

void user::on_pushButton_new_clicked()
{
    CheckInWindow checkin;
    checkin.setAnimalType(animalType);
    checkin.setModal(true);
    checkin.exec();
    this->close();
}

void user::on_pushButton_exists_clicked()
{
    searchCustomerWindow searchCutomer;
    searchCutomer.setAnimalType(animalType);
    searchCutomer.setModal(true);
    searchCutomer.exec();
    this->close();
}
