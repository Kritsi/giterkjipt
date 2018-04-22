#include "secwindow.h"
#include "ui_secwindow.h"
#include "checkinwindow.h"
#include "checkoutwindow.h"
#include "animalprofilwindow.h"
#include "catordog.h"
#include "db.h"
#include "user.h"
#include <QMessageBox>
#include <regex>

secWindow::secWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secWindow)
{
    ui->setupUi(this);

    QPixmap pix("../cats.png");
    pix = pix.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, pix);
    this->setPalette(palette);

    Database mydb;
    mydb.startDB();
    if(!mydb.getMydb().open()) {
    } else {
        QSqlQueryModel * model = new QSqlQueryModel();
        QSqlQuery* qry = new QSqlQuery(mydb.getMydb());

        qry->exec("SELECT a.name as 'Animal name', a.type as Type, ca.cageNr as 'Cage number', c.firstname as 'First name', c.lastname as 'Last name', "
                  "c.tlfNr as 'Telephone number' FROM Animal as a, Customer as c, Cages as ca "
                  "WHERE a.customerNr = c.customerNr AND a.animalId = ca.animalID AND ca.isEmpty=1");
        qry->exec();

        model->setQuery(*qry);
        ui->tableView_Animals->setModel(model);

        mydb.getMydb().close();
    }
}

secWindow::~secWindow()
{
    delete ui;
}

void secWindow::on_btnCheckIn_clicked()
{
    CatOrDog catordog;
    catordog.setModal(true);
    catordog.exec();
}

void secWindow::on_btnCheckOut_clicked()
{
    CheckOutWindow checkout;
    checkout.setModal(true);
    checkout.exec();
}

void secWindow::on_tester_clicked() {
    Database mydb;
    mydb.startDB();
    if(!mydb.getMydb().open()) {
        //Noe gikk galt..
    } else {
        QSqlQueryModel * model = new QSqlQueryModel();
        QSqlQuery* qry = new QSqlQuery(mydb.getMydb());

        qry->exec("SELECT a.name as 'Animal name', a.type as Type, ca.cageNr as 'Cage number', c.firstname as 'First name', c.lastname as 'Last name', "
                  "c.tlfNr as 'Telephone number' FROM Animal as a, Customer as c, Cages as ca "
                  "WHERE a.customerNr = c.customerNr AND a.animalId = ca.animalID AND ca.isEmpty=1");
        qry->exec();

        model->setQuery(*qry);
        ui->tableView_Animals->setModel(model);

        mydb.getMydb().close();
    }
}

void secWindow::on_pushButton_clicked()
{
    string search1 = "";
    string search2 = "";

    string searchWord = ui->inputSearch->text().toStdString();
    regex reg("([a-zæøåA-ZÆØÅ0-9]+)[ ]*([a-zæøåA-ZÆØÅ0-9]*)");
    smatch matches;

    if(std::regex_search(searchWord, matches, reg)) {
        search1 = matches[1];
        search2 = matches[2];
    }

    Database mydb;
    mydb.startDB();

    if(!mydb.getMydb().open()) {
        //Noe gikk galt
    } else {
        QSqlQueryModel * model = new QSqlQueryModel();
        QSqlQuery* qry = new QSqlQuery(mydb.getMydb());

        qry->prepare("SELECT a.name as 'Animal name', a.type as Type, ca.cageNr as 'Cage number', c.firstname as 'First name', c.lastname as 'Last name', c.tlfNr as 'Telephone number'"
                  "FROM Animal as a, Customer as c, Cages as ca WHERE a.customerNr = c.customerNr AND a.animalId = ca.animalID "
                  "AND ca.isEmpty=1 AND (a.name= :search OR c.firstname= :search "
                  "OR c.lastname= :search OR c.tlfNr= :search OR (c.firstname= :search AND c.lastname= :search2))");
        qry->bindValue(":search", QString::fromStdString(search1));
        qry->bindValue(":search2", QString::fromStdString(search2));
        qry->exec();

        model->setQuery(*qry);
        ui->tableView_Animals->setModel(model);

        mydb.getMydb().close();
    }
}

void secWindow::on_tableView_Animals_activated(const QModelIndex &index)
{
    //Henter informasjon fra tabellen
    string animalIndex = ui->tableView_Animals->model()->data(index).toString().toStdString();
    QAbstractItemModel *model = ui->tableView_Animals->model();
    int rowidx = ui->tableView_Animals->selectionModel()->currentIndex().row();
    string aname = model->index(rowidx, 0).data().toString().toStdString();
    int atlf = model->index(rowidx, 5).data().toInt();

    AnimalProfilWindow animalprofil;
    Database mydb;
    mydb.startDB();
    //Henter ut dyre info
    int animalId = mydb.getAnimalId(atlf, aname);
    string animalAge = mydb.getAnimalAge(animalId);
    string animalOwner = mydb.getAnimalOwner(animalId);
    string animalType = mydb.getAnimalType(animalId);
    string animalSex = mydb.getAnimalSex(animalId);
    string animalNeeds = mydb.getAnimalNeeds(animalId);
    //Åpner dyreprofil med riktig informasjon
    animalprofil.setAnimalInfo(aname, animalAge, animalOwner, atlf, animalSex, animalNeeds);
    animalprofil.setAnimalPic(animalType);
    animalprofil.showAnimalInfo();
    animalprofil.setModal(true);
    animalprofil.exec();
}

void secWindow::setUsername(string uname) {
    username = uname;
}

void secWindow::setTotalCages(string tcages) {
    totalCages = tcages;
}

void secWindow::setTotalCatCages(string tcages) {
    totalCatCages = tcages;
}

void secWindow::setTotalDogCages(string tcages) {
    totalDogCages = tcages;
}

void secWindow::setTotalFreeCatCages(string tcages) {
    totalFreeCatCages = tcages;
}

void secWindow::setTotalFreeDogCages(string tcages) {
    totalFreeDogCages = tcages;
}

void secWindow::setTotalFreeCages(string tcages) {
    totalFreeCages = tcages;
}

void secWindow::showMainInfo() {
    ui->label_username->setText(QString::fromStdString(username));
    ui->label_hotelname->setText(QString::fromStdString("Fjordgløtt hotell"));
    ui->label_tlf->setText(QString::fromStdString("41607716"));
    ui->label_adr->setText(QString::fromStdString("Solbakken 12, 1392"));
    ui->label_totelCages->setText(QString::fromStdString(totalCages));
    ui->label_Cat->setText(QString::fromStdString(totalCatCages));
    ui->label_dog->setText(QString::fromStdString(totalDogCages));
    ui->label_freeCatCages->setText(QString::fromStdString(totalFreeCatCages));
    ui->label_freeDogCages->setText(QString::fromStdString(totalFreeDogCages));
    ui->label_freeCages->setText(QString::fromStdString(totalFreeCages));
}
