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

void textBox::setAnimalName(string aname) {
    animalName = aname;
}

void textBox::on_pushButton_clicked() {
    string text = ui->textEdit->toPlainText().toStdString();
    Database mydb;

    mydb.addSpecialNeeds(customer, animalName, text);

    this-close();
}
