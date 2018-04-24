#include "animalprofilwindow.h"
#include "ui_animalprofilwindow.h"
#include "db.h"
#include "customlog.h"
#include <QMessageBox>
#include <QFileDialog>

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


void AnimalProfilWindow::setPic(QString path) {
        QPixmap pix(path);
        ui->labelImg->setPixmap(pix);
        ui->labelImg->setScaledContents(true);
}

void AnimalProfilWindow::setAnimalInfo(QString iname, int tlf) {

    db.startDB();

    name = iname;
    tlfNr = tlf;
    animalID = db.getAnimalId(tlfNr,name);
    age = db.getAnimalAge(animalID);
    owner = db.getAnimalOwner(animalID);
    animalType = db.getAnimalType(animalID);
    sex = db.getAnimalSex(animalID);
    sNeeds = db.getAnimalNeeds(animalID);
    animalPic = db.getAnimalPic(animalID);

    setPic(animalPic);

    db.closeDB();
}

void AnimalProfilWindow::showAnimalInfo() {
    ui->label_name->setText(name);
    ui->label_age->setText(QString::number(age));
    ui->label_owner->setText(owner);
    ui->labe_tlf->setText(QString::number(tlfNr));
    ui->label_sex->setText(sex);
    ui->label_specialNeeds->setText(sNeeds);
}


void AnimalProfilWindow::getLogEntries(){

    db.startDB();

    if(!db.checkDB()) {
        QMessageBox mbx;
        mbx.setText("db not open omg");
        mbx.exec();
    } else {
        QSqlQueryModel * model = new QSqlQueryModel();
        QSqlQuery* qry = new QSqlQuery(db.getMydb());

        qry->prepare("SELECT message, timestamp FROM Log WHERE animalID = :aid;");
        qry->bindValue(":aid", animalID);
        qry->exec();

        model->setQuery(*qry);
        ui->tableView_log->setModel(model);
        db.closeDB();
    }

}

void AnimalProfilWindow::on_btnLogFood_clicked()
{

    db.startDB();

    if(!db.checkDB()){

    } else {
        db.insertLogEntry(animalID, name + " was fed");
        getLogEntries();
    }
}

void AnimalProfilWindow::on_btnLogClean_clicked()
{
    db.startDB();

    if(!db.checkDB()){

    } else {
        db.insertLogEntry(animalID, name + "'s cage was cleaned");
        getLogEntries();
    }

}

void AnimalProfilWindow::on_btnLogCustom_clicked()
{
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

void AnimalProfilWindow::on_btn_Img_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"),
                                                    "../",
                                                    tr("Images (*.png *.xpm *.jpg)"));
    if (!fileName.isEmpty()){
        setPic(fileName);
        animalPic = fileName;
        db.startDB();
        db.setAnimalPic(animalID,fileName);
    }
}
