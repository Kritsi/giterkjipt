#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secwindow.h"
#include "QMessageBox"
#include "db.h"
#include <string>
#include <iostream>

using namespace std;
Database db;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db.startDB();
    if(db.checkDB())
        ui->lblconnection->setText("Up and running!");
    else
        ui->lblconnection->setText("Connection failed..");

    vector<string> exists = db.getPasswordInfo("admin");
    if(exists.empty()){
        db.insertTemplateUsers();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::loginUser (string username, string password) {
    db.startDB();
    vector<string> output = db.getPasswordInfo(username);
    string passordhash = output[0];
    string salt = output[1];

    if(passordhash.empty()){
        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString("Please enter valid login information"));
        msgBox.exec();
        return false;
    }else{
        string newpass = db.hashPassword(salt + password);

        return checkPassword(passordhash,newpass);
    }

}

bool MainWindow::checkPassword(string dbPass, string inputPass){
    db.startDB();
    QMessageBox msgBox;
    msgBox.setText(QString::fromStdString(inputPass+"   "+dbPass));
    msgBox.exec();

    return (dbPass.compare(inputPass) == 0);
}

void MainWindow::on_Login_clicked()
{
    db.startDB();
    string usnm = ui->leUsername->text().toStdString();
    string pswd = ui->lePassword->text().toStdString();


    if(db.UserExists(usnm)){
        if(loginUser(usnm, pswd)){
            string totalCagesNr = db.getNumbersOfCages();
            string totalCagesCat = db.getNumbersOfCatCages();
            string totalCagesDog = db.getNumbersOfDogCages();
            string totalFreeCages = db.getNumbersOfFreeCages();
            string totalFreeCagesCat = db.getNumbersOfFreeCatCages();
            string totalFreeCagesDog = db.getNumbersOfFreeDogCages();
            secWindow secwin;
            secwin.setUsername(usnm);
            secwin.setTotalCages(totalCagesNr);
            secwin.setTotalCatCages(totalCagesCat);
            secwin.setTotalDogCages(totalCagesDog);
            secwin.setTotalFreeCages(totalFreeCages);
            secwin.setTotalFreeCatCages(totalFreeCagesCat);
            secwin.setTotalFreeDogCages(totalFreeCagesDog);
            secwin.showMainInfo();
            secwin.setModal(true);
            this->hide();
            secwin.exec();
        } else {
            ui->lblTitle->setText("Invalid username or password! Try again");
            ui->lblTitle->setStyleSheet("QLabel{color: red; }");
        }
    } else {
        ui->lblTitle->setText("Invalid username or password! Try again");
        ui->lblTitle->setStyleSheet("QLabel{color: red; }");
    }
}

