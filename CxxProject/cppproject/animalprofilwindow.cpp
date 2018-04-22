#include "animalprofilwindow.h"
#include "ui_animalprofilwindow.h"
#include "db.h"

AnimalProfilWindow::AnimalProfilWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnimalProfilWindow)
{
    ui->setupUi(this);

    Database mydb;
    if(!mydb.getMydb().open()) {
    } else {
        QSqlQueryModel * model = new QSqlQueryModel();
        QSqlQuery* qry = new QSqlQuery(mydb.getMydb());

        //Skriv inn sql her
        qry->exec("SELECT a.name as 'Animal name', a.age as Age, a.type as Type, CASE isFemale WHEN 1 THEN 'Female' WHEN 0 THEN 'Male' END as Sex, "
                  "a.specialNeedsText as 'Special Needs', c.firstname as 'First name', c.lastname as 'Last name', c.tlfNr as 'Telephone number'"
                  "FROM Animal as a, Customer as c WHERE a.customerNr = c.customerNr");

        qry->exec();

        model->setQuery(*qry);
        ui->tableView_log->setModel(model);

        mydb.getMydb().close();
    }
}

AnimalProfilWindow::~AnimalProfilWindow()
{
    delete ui;
}

void AnimalProfilWindow::setAnimalPic(string animalType) {
    if(animalType == "Cat") {
        QPixmap pix("../caat.jpg");
        ui->labelImg->setPixmap(pix);
        ui->labelImg->setScaledContents(true);
    } else {
        QPixmap pix("../dog.jpg");
        ui->labelImg->setPixmap(pix);
        ui->labelImg->setScaledContents(true);
    }
}

void AnimalProfilWindow::setAnimalInfo(string iname, string iage, string iowner, int tlf, string isex, string needs) {
    name = iname;
    age = iage;
    owner = iowner;
    tlfNr = to_string(tlf);
    sex = isex;
    sNeeds = needs;
}

void AnimalProfilWindow::showAnimalInfo() {
    ui->label_name->setText(QString::fromStdString(name));
    ui->label_age->setText(QString::fromStdString(age));
    ui->label_owner->setText(QString::fromStdString(owner));
    ui->labe_tlf->setText(QString::fromStdString(tlfNr));
    ui->label_sex->setText(QString::fromStdString(sex));
    ui->label_specialNeeds->setText(QString::fromStdString(sNeeds));
}
