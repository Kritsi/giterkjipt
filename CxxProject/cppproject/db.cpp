#include <QCoreApplication>
#include <iostream>
#include <QMessageBox>
#include "initdb.h"
#include "db.h"

Database::Database() {

}

void Database::startDB(){
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    QString filepath = "../dyrDB.db";
    QFile file(filepath);

    if(!file.exists()){
        this->initDB(filepath);
        mydb.setDatabaseName(filepath);
        //restarts the app
        QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
        exit(12);

    }else{
        mydb.setDatabaseName(filepath);
    }
    mydb.open();
}

QSqlDatabase Database::getMydb() {
    return mydb;
}

void Database::closeDB(){
    mydb.close();
}

void Database::initDB(QString path){
    initdb newdatabase(path);
}

bool Database::checkDB() {
    return mydb.open();
}

void Database::insertCustomer(QString ifirstname, QString ilastname, int itlfnr) {
    if(mydb.open()){

        QSqlQuery qry;
        qry.prepare("SELECT customerNr FROM Customer WHERE tlfNr= :cid;");
        qry.bindValue(":cid", itlfnr);

        bool exists = false;
        if(qry.exec()) {
            if(qry.next()) {
                exists = true;
            }
        }

        if(!exists){
            qry.prepare("INSERT INTO Customer (firstname, lastname, tlfNr) "
                         "VALUES (?, ?, ?)");
            qry.bindValue(0, ifirstname);
            qry.bindValue(1, ilastname);
            qry.bindValue(2, itlfnr);
            qry.exec();
        }
        mydb.close();
    }
}

void Database::insertAnimal(Customer c, QString iname, int iage, QString itype, bool iisFemale, bool ispecialNeeds) {
    if(mydb.open()) {
        int cTlfNr = c.getTlfNr();
        int customerNr;

        QSqlQuery qry;
        qry.prepare("SELECT customerNr FROM Customer WHERE tlfNr= :cid;");
        qry.bindValue(":cid", cTlfNr);
        if(qry.exec()) {
            if(qry.next()) {
                customerNr = qry.value(0).toInt();
            }
        }

        QDate datetime;
        QString time = datetime.currentDate().toString();

        qry.prepare("INSERT INTO Animal (name, age, type, isFemale, specialNeeds, customerNr, checkInDate) "
                    "VALUES (?, ?, ?, ?, ?, ?, ?)");
        qry.bindValue(0, iname);
        qry.bindValue(1, iage);
        qry.bindValue(2, itype);
        qry.bindValue(3, iisFemale);
        qry.bindValue(4, ispecialNeeds);
        qry.bindValue(5, customerNr);
        qry.bindValue(6, time);
        qry.exec();

        if(itype.compare("Cat") == 0){
            QMessageBox mbx;
            mbx.setText("is cate");
            mbx.exec();

            insertAnimalPic(getAnimalId(cTlfNr,iname), "../defaultcat.jpg");
        }else{
            insertAnimalPic(getAnimalId(cTlfNr,iname), "../defaultdog.jpg");
}
        mydb.close();
    }
}

void Database::deleteAnimal(int tlfNr, QString name) {
    if(mydb.open()) {
        int customerNr;

        QSqlQuery qry;
        qry.prepare("SELECT customerNr FROM Customer WHERE tlfNr= :cid;");
        qry.bindValue(":cid", tlfNr);
        if(qry.exec()) {
            if(qry.next()) {
                customerNr = qry.value(0).toInt();
            }
        }

        qry.prepare("SELECT animalId FROM Animal WHERE customerNr = :cid AND name = :aname;");
        qry.bindValue(":cid", customerNr);
        qry.bindValue(":aname", name);

        int animalId;
        if(qry.exec()) {
            if(qry.next()) {
                animalId = qry.value(0).toInt();
            }
        }

        qry.prepare("DELETE FROM Animal WHERE animalId = :aid;");
        qry.bindValue(":aid", animalId);
        qry.exec();

        mydb.close();
    }
}

void Database::addSpecialNeeds(Customer c, QString animalName, QString spText) {
    if(mydb.open()) {
        int customerNr;

        QSqlQuery qry;
        qry.prepare("SELECT customerNr FROM Customer WHERE tlfNr= :cid;");
        qry.bindValue(":cid", c.getTlfNr());

        if(qry.exec()) {
            if(qry.next()) {
                customerNr = qry.value(0).toInt();
            }
        }

        qry.prepare("UPDATE Animal SET specialNeedsText= :atext WHERE customerNr= :cnr AND name= :aname;");
        qry.bindValue(":atext", spText);
        qry.bindValue(":cnr", customerNr);
        qry.bindValue(":aname", animalName);
        qry.exec();

        mydb.close();
    }
}

Customer Database::createCustomer(int tlf) {
    if(mydb.open()){
        QString dbFirstname = "Firstname";
        QString dbLastname = "Lastname";

        QSqlQuery qry;
        qry.prepare("SELECT firstname, lastname FROM Customer WHERE tlfNr= :ctlfNr;");
        qry.bindValue(":ctlfNr", tlf);

        if(qry.exec()) {
            if(qry.next()) {
                dbFirstname = qry.value(0).toString();
                dbLastname = qry.value(1).toString();
            }
        }

        mydb.close();
        return Customer(dbFirstname, dbLastname, tlf);
    }
    return Customer("Firstname", "Lastname", 12345678);
}

bool Database::searchCustomer(int tlf) {
    if(mydb.open()) {

        QSqlQuery qry;
        qry.prepare("SELECT customerNr FROM Customer WHERE tlfNr= :ctlfNr;");
        qry.bindValue(":ctlfNr", tlf);

        if(qry.exec()) {
            if(qry.next()) {
                return true;
            }
        }
    }
    return false;
}

int Database::getAnimalId(int tlfNr, QString animalName) {
    if(mydb.open()) {

        QSqlQuery qry;
        qry.prepare("SELECT animalId FROM Animal as a, Customer as c WHERE c.customerNr = a.customerNr AND c.tlfNr= :ctlf And a.name= :aname");
        qry.bindValue(":ctlf", tlfNr);
        qry.bindValue(":aname", animalName);

        if(qry.exec()) {
            if(qry.next()) {
                return qry.value(0).toInt();
            }
        }
    }
    return 0;
}

void Database::setAnimalPic(int animalid, QString path){
    if(mydb.open()) {
        QSqlQuery qry;
        qry.prepare("UPDATE Pictures SET picLocation= :pth WHERE animalID = :aid");
        qry.bindValue(":pth", path);
        qry.bindValue(":aid", animalid);

        qry.exec();
 }
}

void Database::insertAnimalPic(int animalid, QString path){
    if(mydb.open()) {
        QSqlQuery qry;
        qry.prepare("INSERT INTO Pictures (animalID, picLocation) VALUES (:aid, :pth);");
        qry.bindValue(":aid", animalid);
        qry.bindValue(":pth", path);

        qry.exec();
 }
}

QString Database::getAnimalPic(int animalid){
    if(mydb.open()) {

        QSqlQuery qry;
        qry.prepare("SELECT picLocation FROM Pictures WHERE animalID = :aid");
        qry.bindValue(":aid", animalid);

        if(qry.exec()) {
            if(qry.next()) {
                return qry.value(0).toString();
            }
        }
    }
    return "";
}

int Database::getAnimalAge(int animalId) {
    if(mydb.open()) {

        QSqlQuery qry;
        qry.prepare("SELECT age FROM Animal WHERE animalId= :aid");
        qry.bindValue(":aid", animalId);

        if(qry.exec()) {
            if(qry.next()) {
                return qry.value(0).toInt();
            }
        }
    }
    return 0;
}

QString Database::getAnimalOwner(int animalId) {
    if(mydb.open()) {

        QSqlQuery qry;
        qry.prepare("SELECT firstname, lastname FROM Animal as a, Customer as c WHERE a.customerNr = c.customerNr AND a.animalId= :aid;");
        qry.bindValue(":aid", animalId);

        if(qry.exec()) {
            if(qry.next()) {        
                return qry.value(0).toString() + " " + qry.value(1).toString();
            }
        }
    }
    return "";
}

QString Database::getAnimalType(int animalId) {
    if(mydb.open()) {

        QSqlQuery qry;
        qry.prepare("SELECT type FROM Animal WHERE animalId= :atype");
        qry.bindValue(":atype", animalId);

        if(qry.exec()) {
            if(qry.next()) {
                return qry.value(0).toString();
            }
        }
    }
    return "";
}

QString Database::getAnimalSex(int animalId) {
    int sex = 0;

    if(mydb.open()) {

        QSqlQuery qry;
        qry.prepare("SELECT isFemale FROM Animal WHERE animalId= :aid");
        qry.bindValue(":aid", animalId);

        if(qry.exec()) {
            if(qry.next()) {
                sex = qry.value(0).toInt();
            }
        }
        mydb.close();
    }
    return (sex == 0 ? "Male" : "Female");
}

QString Database::getAnimalNeeds(int animalId) {
    if(mydb.open()) {

        QSqlQuery qry;
        qry.prepare("SELECT specialNeedsText FROM Animal WHERE animalId= :aid");
        qry.bindValue(":aid", animalId);

        if(qry.exec()) {
            if(qry.next()) {
                return qry.value(0).toString();
            }
        }

    }
    return "";
}

string Database::getAnimalCheckInDate(int animalId) {
    string animalCheckInDate = "";

    if(mydb.open()) {
        QSqlQuery qry;

        qry.prepare("SELECT checkInDate FROM Animal WHERE animalId= :aid");
        qry.bindValue(":aid", animalId);

        if(qry.exec())
            if(qry.next())
                animalCheckInDate = qry.value(0).toString().toStdString();

        mydb.close();
    }

    return animalCheckInDate;
}

int Database::getNumbersOfCages() {
    if(mydb.open()) {

        QSqlQuery qry;
        if(qry.exec("SELECT COUNT(*) FROM Cages;")) {
            if(qry.next()) {
                return qry.value(0).toInt();
            }
        }
    }
    return 0;
}

int Database::getNumbersOfCatCages() {
    if(mydb.open()) {

        QSqlQuery qry;
        if(qry.exec("SELECT COUNT(*) FROM Cages WHERE Type='Cat';")) {
            if(qry.next()) {
                return qry.value(0).toInt();
            }
        }
    }
    return 0;
}

int Database::getNumbersOfDogCages() {
    if(mydb.open()) {

        QSqlQuery qry;
        if(qry.exec("SELECT COUNT(*) FROM Cages WHERE Type='Dog';")) {
            if(qry.next()) {
                return qry.value(0).toInt();
            }
        }
    }
    return 0;
}

int Database::getNumbersOfFreeCatCages() {
    if(mydb.open()) {
        QSqlQuery qry;
        if(qry.exec("SELECT COUNT(*) FROM Cages WHERE type='Cat' AND isEmpty=0;")) {
            if(qry.next()) {
                return qry.value(0).toInt();
            }
        }
    }
    return 0;
}

int Database::getNumbersOfFreeDogCages() {
    if(mydb.open()) {
        QSqlQuery qry;

        if(qry.exec("SELECT COUNT(*) FROM Cages WHERE type='Dog' AND isEmpty=0;")) {
            if(qry.next()) {
                return qry.value(0).toInt();

            }
        }
    }
    return 0;
}

int Database::getNumbersOfFreeCages() {
    if(mydb.open()) {
        QSqlQuery qry;

        if(qry.exec("SELECT COUNT(*) FROM Cages WHERE isEmpty=0;")) {
            if(qry.next()) {
                return qry.value(0).toInt();
            }
        }
    }
    return 0;
}

bool Database::checkFreeCatCages() {
   int cages = getNumbersOfFreeCatCages();
   return (cages > 0 ? true : false);
}

bool Database::checkFreeDogCages() {
    int cages = getNumbersOfFreeDogCages();
    return (cages > 0 ? true : false);
}

void Database::setCatInCage(int animalId) {
    if(mydb.open()) {

        QSqlQuery qry;
        qry.prepare("UPDATE Cages SET animalId= :aid, isEmpty=1 WHERE type='Cat' AND cageID="
                 "(SELECT cageID FROM Cages WHERE isEmpty=0 AND type='Cat' ORDER BY cageNr);");
        qry.bindValue(":aid", animalId);
        qry.exec();

        mydb.close();
    }
}

void Database::setDogInCage(int animalId) {
    if(mydb.open()) {

        QSqlQuery qry;
        qry.prepare("UPDATE Cages SET animalId= :aid, isEmpty=1 WHERE Type='Dog' AND cageID="
                    "(SELECT cageID FROM Cages WHERE isEmpty=0 AND type='Dog' ORDER BY cageNr);");
        qry.bindValue(":aid", animalId);
        qry.exec();

        mydb.close();
    }
}

void Database::removeAnimalFromCage(int animalId) {
    if(mydb.open()) {

        QSqlQuery qry;
        qry.prepare("UPDATE Cages SET animalId= NULL, isEmpty=0 WHERE animalId= :aid;");
        qry.bindValue(":aid", animalId);
        qry.exec();

        mydb.close();
    }
}

vector<string> Database::getPasswordInfo(QString iusername){
    vector<string> returnable;

    QSqlQuery qry;
    qry.prepare("SELECT Password,Salt FROM Users WHERE Username = ?;");
    qry.bindValue(0, iusername);

   if(qry.exec()) {
        if(qry.next()) {
            returnable.push_back(qry.value(0).toString().toStdString());
            returnable.push_back(qry.value(1).toString().toStdString());
            return returnable;
       }
   }
   return returnable;
}

bool Database::UserExists(QString iusername){
    QSqlQuery qry;
    qry.prepare("SELECT Username FROM Users WHERE Username = ?;");
    qry.bindValue(0, iusername);

    if(qry.exec()) {
         if(qry.next()) {
             return true;
        }
    }
    return false;
}

void Database::insertTemplateUsers(){
    QString user1 = "admin";
    QString salt1 = "aksdjilkepsa1";
    string password1 = hashPassword(salt1.toStdString() + "admin");

    QString user2 = "kritsi";
    QString salt2 = "rtfvubkifsw2";
    string password2 = hashPassword(salt2.toStdString() + "potet");

    QString user3 = "marius";
    QString salt3 = "s5drtyvghbåp3";
    string password3 = hashPassword(salt3.toStdString() + "aubergine");

    insertUser("Administrator", user1 , QString::fromStdString(password1) , salt1);
    insertUser("Kristine" , user2 , QString::fromStdString(password2) , salt2);
    insertUser("Marius" , user3 , QString::fromStdString(password3) , salt3);

}

void Database::insertUser(QString iname, QString iun, QString ipass, QString isalt){
    QSqlQuery qry;
    qry.prepare("INSERT INTO Users (name, username, salt, password) "
                "VALUES (?, ?, ?, ? )");
    qry.bindValue(0, iname);
    qry.bindValue(1, iun);
    qry.bindValue(2, isalt);
    qry.bindValue(3, ipass);

    qry.exec();

}

string Database::hashPassword(string password){
    hash<string> hash;
    size_t temp = hash(password);
    string hashoutput = to_string(temp);
    return hashoutput;
}

void Database::insertLogEntry(int animalid, QString message){
       QDateTime datetime;
       QString time = datetime.currentDateTime().toString();

       QSqlQuery qry;

       qry.prepare("INSERT INTO Log (animalid, message, timestamp) "
                   "VALUES (?,?, ?)");
       qry.bindValue(0, animalid);
       qry.bindValue(1, message);
       qry.bindValue(2, time);

       qry.exec();
}



