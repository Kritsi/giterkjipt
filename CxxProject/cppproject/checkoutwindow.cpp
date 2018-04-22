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
    //ui->backgroundImg->setPixmap(pix);
    this->setPalette(palette);
    //ui->backgroundImg->setScaledContents(true);
}

CheckOutWindow::~CheckOutWindow()
{
    delete ui;
}

void CheckOutWindow::on_buttonBox_accepted()
{
    string tlfNr = ui->inputFindTlf->text().toStdString();
    string name = ui->inputFindName->text().toStdString();

    QMessageBox msgBox;
    string msg = "";

    msg += tlfNr + " " + name;

    int tlf = stoi(tlfNr);

    msgBox.setText(QString::fromStdString(msg));
    msgBox.exec();

    Database mydb;
    mydb.deleteAnimal(tlf, name);
}

void CheckOutWindow::on_buttonBox_rejected()
{
    this->close();
}
