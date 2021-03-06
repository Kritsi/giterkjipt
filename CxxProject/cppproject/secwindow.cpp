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
    setBackground("../cats.png");

    db.startDB();
    if(db.checkDB()) {

        QSqlQueryModel * model = new QSqlQueryModel();
        QSqlQuery* qry = new QSqlQuery(db.getMydb());

        qry->exec("SELECT a.name as 'Animal name', a.type as Type, ca.cageNr as 'Cage number', c.firstname as 'First name', c.lastname as 'Last name', "
                  "c.tlfNr as 'Telephone number' FROM Animal as a, Customer as c, Cages as ca "
                  "WHERE a.customerNr = c.customerNr AND a.animalId = ca.animalID AND ca.isEmpty=1");

        model->setQuery(*qry);
        ui->tableView_Animals->setModel(model);

        db.closeDB();
    }

    QPixmap pix2("../catdog.jpg");
    ui->label_img->setPixmap(pix2);
    ui->label_img->setScaledContents(true);
}

secWindow::~secWindow()
{
    delete ui;
}

void secWindow::setBackground(QString path){
    QPixmap pix(path);
    pix = pix.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, pix);
    this->setPalette(palette);
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
    db.startDB();
    if(db.checkDB()) {
        QSqlQueryModel * model = new QSqlQueryModel();
        QSqlQuery* qry = new QSqlQuery(db.getMydb());

        qry->exec("SELECT a.name as 'Animal name', a.type as Type, ca.cageNr as 'Cage number', c.firstname as 'First name', c.lastname as 'Last name', "
                  "c.tlfNr as 'Telephone number' FROM Animal as a, Customer as c, Cages as ca "
                  "WHERE a.customerNr = c.customerNr AND a.animalId = ca.animalID AND ca.isEmpty=1");
        model->setQuery(*qry);
        ui->tableView_Animals->setModel(model);

        db.closeDB();
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

    db.startDB();

    if(db.checkDB()) {
        QSqlQueryModel * model = new QSqlQueryModel();
        QSqlQuery* qry = new QSqlQuery(db.getMydb());

        qry->prepare("SELECT a.name as 'Animal name', a.type as Type, ca.cageNr as 'Cage number', c.firstname as 'First name', c.lastname as 'Last name', c.tlfNr as 'Telephone number'"
                  "FROM Animal as a, Customer as c, Cages as ca WHERE a.customerNr = c.customerNr AND a.animalId = ca.animalID "
                  "AND ca.isEmpty=1 AND (a.name= :search OR c.firstname= :search OR a.type= :search "
                  "OR c.lastname= :search OR c.tlfNr= :search OR (c.firstname= :search AND c.lastname= :search2))");
        qry->bindValue(":search", QString::fromStdString(search1));
        qry->bindValue(":search2", QString::fromStdString(search2));
        qry->exec();

        model->setQuery(*qry);
        ui->tableView_Animals->setModel(model);

        db.closeDB();
    }
}

void secWindow::on_tableView_Animals_activated(const QModelIndex &index)
{
    QString animalIndex = ui->tableView_Animals->model()->data(index).toString();
    QAbstractItemModel *model = ui->tableView_Animals->model();
    int rowidx = ui->tableView_Animals->selectionModel()->currentIndex().row();
    QString aname = model->index(rowidx, 0).data().toString();
    int atlf = model->index(rowidx, 5).data().toInt();

    //Opens Animal Profile Window with data from table
    AnimalProfilWindow animalprofil;
    animalprofil.setAnimalInfo(aname, atlf);
    animalprofil.showAnimalInfo();
    animalprofil.getLogEntries();
    animalprofil.setModal(true);
    animalprofil.exec();
}

void secWindow::setUsername(QString uname) {
    username = uname;
}

void secWindow::setTotalCages(int tcages) {
    totalCages = tcages;
}

void secWindow::setTotalCatCages(int tcages) {
    totalCatCages = tcages;
}

void secWindow::setTotalDogCages(int tcages) {
    totalDogCages = tcages;
}

void secWindow::setTotalFreeCatCages(int tcages) {
    totalFreeCatCages = tcages;
}

void secWindow::setTotalFreeDogCages(int tcages) {
    totalFreeDogCages = tcages;
}

void secWindow::setTotalFreeCages(int tcages) {
    totalFreeCages = tcages;
}

void secWindow::showMainInfo() {
    ui->label_username->setText(username);
    ui->label_hotelname->setText("Fjordgløtt hotell");
    ui->label_tlf->setText("41607716");
    ui->label_adr->setText("Solbakken 12, 1392");
    ui->label_totelCages->setText(QString::number(totalCages));
    ui->label_Cat->setText(QString::number(totalCatCages));
    ui->label_dog->setText(QString::number(totalDogCages));
    ui->label_freeCatCages->setText(QString::number(totalFreeCatCages));
    ui->label_freeDogCages->setText(QString::number(totalFreeDogCages));
    ui->label_freeCages->setText(QString::number(totalFreeCages));
}
