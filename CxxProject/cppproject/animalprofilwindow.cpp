#include "animalprofilwindow.h"
#include "ui_animalprofilwindow.h"
#include "db.h"
#include "customlog.h"
#include <QMessageBox>

AnimalProfilWindow::AnimalProfilWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnimalProfilWindow)
{
    ui->setupUi(this);
}

AnimalProfilWindow::~AnimalProfilWindow()
{
    delete ui;
}

void AnimalProfilWindow::setAnimalPic(string animalType) {
    if(animalType == "Cat") {
        QPixmap pix("../Nussi.jpg");
        ui->labelImg->setPixmap(pix);
        ui->labelImg->setScaledContents(true);
    } else {
        QPixmap pix("../dog.jpg");
        ui->labelImg->setPixmap(pix);
        ui->labelImg->setScaledContents(true);
    }
}

void AnimalProfilWindow::setAnimalInfo(string iname, string iage, string iowner, int tlf, string isex, string needs) {
    Database mydb;
    mydb.startDB();

    name = iname;
    age = iage;
    owner = iowner;
    tlfNr = tlf;
    sex = isex;
    sNeeds = needs;

    animalID = mydb.getAnimalId(tlf,name);

    mydb.closeDB();
}

void AnimalProfilWindow::showAnimalInfo() {
    ui->label_name->setText(QString::fromStdString(name));
    ui->label_age->setText(QString::fromStdString(age));
    ui->label_owner->setText(QString::fromStdString(owner));
    ui->labe_tlf->setText(QString::fromStdString(to_string(tlfNr)));
    ui->label_sex->setText(QString::fromStdString(sex));
    ui->label_specialNeeds->setText(QString::fromStdString(sNeeds));
}


void AnimalProfilWindow::getLogEntries(){
    Database mydb;
    mydb.startDB();

    if(!mydb.checkDB()) {
        QMessageBox mbx;
        mbx.setText("db not open omg");
        mbx.exec();
    } else {
        QSqlQueryModel * model = new QSqlQueryModel();
        QSqlQuery* qry = new QSqlQuery(mydb.getMydb());

        qry->prepare("SELECT message, timestamp FROM Log WHERE animalID = :aid;");
        qry->bindValue(":aid", animalID);
        qry->exec();

        model->setQuery(*qry);
        ui->tableView_log->setModel(model);
        mydb.closeDB();
    }

}

void AnimalProfilWindow::on_btnLogFood_clicked()
{
    Database db;
    db.startDB();

    if(!db.checkDB()){

    } else {
        db.insertLogEntry(animalID, QString::fromStdString(name + " was fed"));
        getLogEntries();
    }
}

void AnimalProfilWindow::on_btnLogClean_clicked()
{
    Database db;
    db.startDB();

    if(!db.checkDB()){

    } else {
        db.insertLogEntry(animalID, QString::fromStdString(name + "'s cage was cleaned"));
        getLogEntries();
    }

}

void AnimalProfilWindow::on_btnLogCustom_clicked()
{
    Database db;
    db.startDB();

    customlog clog;
    clog.setModal(true);
    clog.exec();

    if(!db.checkDB()){

    } else {
        db.insertLogEntry(animalID, clog.getMessage());
        getLogEntries();
    }


}
