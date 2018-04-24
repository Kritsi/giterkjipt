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

bool MainWindow::loginUser (QString username, string password) {
    db.startDB();
    vector<string> output = db.getPasswordInfo(username);
    string passordhash = output[0];
    string salt = output[1];

    if(passordhash.empty()){
        QMessageBox msgBox;
        msgBox.setText("Please enter valid login information");
        msgBox.exec();
        return false;
    }else{
        string newpass = db.hashPassword(salt + password);

        return checkPassword(passordhash,newpass);
    }

}

bool MainWindow::checkPassword(string dbPass, string inputPass){
    return (dbPass.compare(inputPass) == 0);
}

void MainWindow::on_Login_clicked()
{
    db.startDB();
    QString usnm = ui->leUsername->text();
    string pswd = ui->lePassword->text().toStdString();


    if(db.UserExists(usnm)){
        if(loginUser(usnm, pswd)){
            int totalCagesNr = db.getNumbersOfCages();
            int totalCagesCat = db.getNumbersOfCatCages();
            int totalCagesDog = db.getNumbersOfDogCages();
            int totalFreeCages = db.getNumbersOfFreeCages();
            int totalFreeCagesCat = db.getNumbersOfFreeCatCages();
            int totalFreeCagesDog = db.getNumbersOfFreeDogCages();
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

