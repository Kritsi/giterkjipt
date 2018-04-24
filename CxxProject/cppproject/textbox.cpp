#include "textbox.h"
#include "ui_textbox.h"
#include "db.h"
#include <iostream>

using namespace std;

textBox::textBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::textBox)
{
    ui->setupUi(this);
}

textBox::~textBox()
{
    delete ui;
}

void textBox::setCustomer(Customer c) {
    customer = c;
}

void textBox::setAnimalName(QString aname) {
    animalName = aname;
}

void textBox::on_pushButton_clicked() {
    QString text = ui->textEdit->toPlainText();
    Database mydb;
    mydb.startDB();

    mydb.addSpecialNeeds(customer, animalName, text);

    this-close();
}
