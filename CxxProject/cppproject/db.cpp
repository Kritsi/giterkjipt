#include <QCoreApplication>
#include <iostream>
#include "QMessageBox"
#include "initdb.h"
#include "db.h"

Database::Database() {

}

void Database::startDB(){
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    QString fpath = "../dyrDB.db";
    QFile filepath(fpath);

    if(!filepath.exists()){
        this->initDB(fpath);
        mydb.setDatabaseName(fpath);
        QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
        exit(12);
    }else{
        mydb.setDatabaseName(fpath);
    }
    mydb.open();
}

QSqlDatabase Database::getMydb() {
    return mydb;
}

void Database::insertCustomer(string ifirstname, string ilastname, int itlfnr) {
    QMessageBox msgBox;

    string msg = "";

    if(!mydb.open()) {
        msg += "Nei.. Feilet";
    } else {
        msg += "Ja, inne! :D ";

        bool eksisterer = false;

        QSqlQuery qry;

        qry.prepare("SELECT customerNr FROM Customer WHERE tlfNr= :cid;");
        qry.bindValue(":cid", itlfnr);

        if(qry.exec()) {
            msg += " qry kjørt ";
            if(qry.next()) {
                eksisterer = true;
                msg += " Gikk inn, kunde eksiterer ";
            }
        }

        msg += " eksisterer: " + to_string(eksisterer);
        if(!eksisterer){
            msg += " Kunde eksisterer ikke, oppretter ny ";
            qry.prepare("INSERT INTO Customer (firstname, lastname, tlfNr) "
                          "VALUES (?, ?, ?)");
            qry.bindValue(0, QString::fromStdString(ifirstname));
            qry.bindValue(1, QString::fromStdString(ilastname));
            qry.bindValue(2, itlfnr);
            qry.exec();
        }

        mydb.close();
    }
    msg += ifirstname + " " + ilastname + " " + to_string(itlfnr) + " ";

    msgBox.setText(QString::fromStdString(msg));

    msgBox.exec();
}

void Database::insertAnimal(Customer c, string iname, int iage, string itype, bool iisFemale, bool ispecialNeeds) {
    QMessageBox msgBox;

    string msg = "";

    if(!mydb.open()) {
        msg += "Nei.. Feilet";
    } else {
        msg += "Jaa, inne! :D ";

        QSqlQuery qry;

        int customerNr = 7;

        qry.prepare("SELECT customerNr FROM Customer WHERE tlfNr= :cid;");
        qry.bindValue(":cid", stoi(c.getTlfNr()));
        if(qry.exec()) {
            if(qry.next()) {
                msg += " Gikk inn ";
                customerNr = qry.value(0).toInt();
            }
        }

        QDate datetime;
        QString time = datetime.currentDate().toString();

        msg += "KundeNr: " + to_string(customerNr);

        qry.prepare("INSERT INTO Animal (name, age, type, isFemale, specialNeeds, customerNr, checkInDate) "
                    "VALUES (?, ?, ?, ?, ?, ?, ?)");
        qry.bindValue(0, QString::fromStdString(iname));
        qry.bindValue(1, iage);
        qry.bindValue(2, QString::fromStdString(itype));
        qry.bindValue(3, iisFemale);
        qry.bindValue(4, ispecialNeeds);
        qry.bindValue(5, customerNr);
        qry.bindValue(6, time);
        qry.exec();

        mydb.close();
    }

    msgBox.setText(QString::fromStdString(msg));

    msgBox.exec();
}

void Database::deleteAnimal(int tlfNr, string name) {
    QMessageBox msgBox;
    string msg = "";

    if(!mydb.open()) {
        msg += "Nei.. Feilet";
    } else {
        msg += "Jaa!! :DDDD";

        int customerNr = 7;

        QSqlQuery qry;
        qry.prepare("SELECT customerNr FROM Customer WHERE tlfNr= :cid;");
        qry.bindValue(":cid", tlfNr);
        if(qry.exec()) {
            if(qry.next()) {
                msg += " Gikk inn ";
                customerNr = qry.value(0).toInt();
            }
        }

        qry.prepare("SELECT animalId FROM Animal WHERE customerNr = :cid AND name = :aname;");
        qry.bindValue(":cid", customerNr);
        qry.bindValue(":aname", QString::fromStdString(name));

        int animalId = 9;
        if(qry.exec()) {
            if(qry.next()) {
                msg += " Gikk inn ";
                animalId = qry.value(0).toInt();
            }
        }

        qry.prepare("DELETE FROM Animal WHERE animalId = :aid;");
        qry.bindValue(":aid", animalId);

        bool success = false;
        success = qry.exec();
        if(!success) {
              msg += " removePerson error ";
        } else {
            msg += " Den er nå slettet ";
        }

        msg += to_string(customerNr) + " " + to_string(animalId);

        mydb.close();
    }

    msgBox.setText(QString::fromStdString(msg));

    msgBox.exec();
}

void Database::addSpecialNeeds(Customer c, string animalName, string spText) {
    QMessageBox msgBox;
    string msg = "";

    if(!mydb.open()) {
        msg += "Nei.. Feilet";
    } else {
        msg += "Jaa!! :DDDD";

        QSqlQuery qry;

        int customerNr = 8;

        qry.prepare("SELECT customerNr FROM Customer WHERE tlfNr= :cid;");
        qry.bindValue(":cid", stoi(c.getTlfNr()));
        if(qry.exec()) {
            if(qry.next()) {
                msg += " Gikk inn ";
                customerNr = qry.value(0).toInt();
            }
        }

        msg += customerNr;

        qry.prepare("UPDATE Animal SET specialNeedsText= :atext WHERE customerNr= :cnr AND name= :aname;");
        qry.bindValue(":atext", QString::fromStdString(spText));
        qry.bindValue(":cnr", customerNr);
        qry.bindValue(":aname", QString::fromStdString(animalName));

        qry.exec();
        mydb.close();
    }

    msgBox.setText(QString::fromStdString(msg));
    msgBox.exec();
}

Customer Database::createCustomer(int tlf) {
    QMessageBox msgBox;
    string msg = "";

    Customer c;

    if(!mydb.open()) {
        msg += "Nei.. Feilet";
    } else {
        msg += "Jaa, inne! :D \n ";

        QSqlQuery qry;

        string dbFirstname = "Fornavn: ";
        string dbLastname = "Etternavn: ";

        qry.prepare("SELECT firstname, lastname FROM Customer WHERE tlfNr= :ctlfNr;");
        qry.bindValue(":ctlfNr", tlf);
        int firstnameNr = qry.record().indexOf("firstname");
        int lastnameNr = qry.record().indexOf("lastname");

        if(qry.exec()) {
            if(qry.next()) {
                msg += " Gikk inn ";
                dbFirstname = qry.value(0).toString().toStdString();
                dbLastname = qry.value(1).toString().toStdString();
            }
        }

        msg += " " + dbFirstname + " ";
        msg += " " + dbLastname + " ";

        //Opprett et kunde objekt
        c = Customer(dbFirstname, dbLastname, to_string(tlf));

        mydb.close();
    }

    msgBox.setText(QString::fromStdString(msg));
    msgBox.exec();

    return c;
}

bool Database::searchCustomer(int tlf) {
    QMessageBox msgBox;
    string msg = "";

    bool customerExists = false;

    if(!mydb.open()) {
        msg += "Nei.. Feilet";
    } else {
        msg += "Jaa, inne! :D \n ";

        QSqlQuery qry;

        qry.prepare("SELECT customerNr FROM Customer WHERE tlfNr= :ctlfNr;");
        qry.bindValue(":ctlfNr", tlf);

        if(qry.exec()) {
            if(qry.next()) {
                customerExists = true;
                msg += " Gikk inn ";
            }
        }
        mydb.close();
    }

    msgBox.setText(QString::fromStdString(msg));
    msgBox.exec();

    return customerExists;
}

//Kan ikke lete etter dyr på kundeinfo, fordi kunde kan ha flere dyr
//Må lete på navn eller lignende, men vet ikke hva, fordi det må være unikt
//kanskje telefonnr + navn.. smart ;DDDD
int Database::getAnimalId(int tlfNr, string animalName) {
    int animalId = 0;

    if(!mydb.open()) {

    } else {
        QSqlQuery qry;

        qry.prepare("SELECT animalId FROM Animal as a, Customer as c WHERE c.customerNr = a.customerNr AND c.tlfNr= :ctlf And a.name= :aname");
        qry.bindValue(":ctlf", tlfNr);
        qry.bindValue(":aname", QString::fromStdString(animalName));

        if(qry.exec()) {
            if(qry.next()) {
                animalId = qry.value(0).toInt();
            }
        }

        mydb.close();
    }

    return animalId;
}

string Database::getAnimalAge(int animalId) {
    string msg = "";

    int animalAge = 0;

    if(!mydb.open()) {

    } else {
        QSqlQuery qry;

        qry.prepare("SELECT age FROM Animal WHERE animalId= :aid");
        qry.bindValue(":aid", animalId);

        if(qry.exec()) {
            if(qry.next()) {
                animalAge = qry.value(0).toInt();
            }
        }
        mydb.close();
    }

    return to_string(animalAge);
}

string Database::getAnimalOwner(int animalId) {
    string animalOwnerFn = "";
    string animalOwnerLn = "";

    if(!mydb.open()) {

    } else {
        QSqlQuery qry;

        qry.prepare("SELECT firstname, lastname FROM Animal as a, Customer as c WHERE a.customerNr = c.customerNr AND a.animalId= :aid;");
        qry.bindValue(":aid", animalId);

        if(qry.exec()) {
            if(qry.next()) {
                animalOwnerFn = qry.value(0).toString().toStdString();
                animalOwnerLn = qry.value(1).toString().toStdString();
            }
        }

        mydb.close();
    }

    string ownerName = animalOwnerFn + " " + animalOwnerLn;
    return ownerName;
}

string Database::getAnimalType(int animalId) {
    string animalType = "";

    if(!mydb.open()) {

    } else {
        QSqlQuery qry;

        qry.prepare("SELECT type FROM Animal WHERE animalId= :atype");
        qry.bindValue(":atype", animalId);

        if(qry.exec()) {
            if(qry.next()) {
                animalType = qry.value(0).toString().toStdString();
            }
        }

        mydb.close();
    }
    return animalType;
}

string Database::getAnimalSex(int animalId) {
    string animalSex = "";
    int sex = 0;

    if(!mydb.open()) {

    } else {
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
    if(sex == 0) {
        animalSex = "Male";
    } else {
        animalSex = "Female";
    }
    return animalSex;
}

string Database::getAnimalNeeds(int animalId) {
    string animalNeeds = "";

    if(!mydb.open()) {

    } else {
        QSqlQuery qry;

        qry.prepare("SELECT specialNeedsText FROM Animal WHERE animalId= :aid");
        qry.bindValue(":aid", animalId);

        if(qry.exec()) {
            if(qry.next()) {
                animalNeeds = qry.value(0).toString().toStdString();
            }
        }

        mydb.close();
    }
    return animalNeeds;
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

string Database::getNumbersOfCages() {
    string cagesNr = "";

    if(mydb.open()) {
        QSqlQuery qry;

        if(qry.exec("SELECT COUNT(*) FROM Cages;"))
            if(qry.next())
                cagesNr = qry.value(0).toString().toStdString();

        mydb.close();
    }
    return cagesNr;
}

string Database::getNumbersOfCatCages() {
    string cagesNr = "";

    if(mydb.open()) {
        QSqlQuery qry;

        if(qry.exec("SELECT COUNT(*) FROM Cages WHERE Type='Cat';"))
            if(qry.next())
                cagesNr = qry.value(0).toString().toStdString();

        mydb.close();
    }
    return cagesNr;
}

string Database::getNumbersOfDogCages() {
    string cagesNr = "";

    if(!mydb.open()) {
        //Noe gikk galt..
    } else {
        QSqlQuery qry;

        if(qry.exec("SELECT COUNT(*) FROM Cages WHERE Type='Dog';")) {
            if(qry.next()) {
                cagesNr = qry.value(0).toString().toStdString();
            }
        }

        mydb.close();
    }
    return cagesNr;
}

string Database::getNumbersOfFreeCatCages() {
    string cagesNr = "";

    if(!mydb.open()) {
        //Noe gikk galt..
    } else {
        QSqlQuery qry;
        if(qry.exec("SELECT COUNT(*) FROM Cages WHERE type='Cat' AND isEmpty=0;")) {
            if(qry.next()) {
                cagesNr = qry.value(0).toString().toStdString();
            }
        }
        mydb.close();
    }
    return cagesNr;
}

string Database::getNumbersOfFreeDogCages() {
    string cagesNr = "";

    if(!mydb.open()) {
        //Noe gikk galt..
    } else {
        QSqlQuery qry;
        if(qry.exec("SELECT COUNT(*) FROM Cages WHERE type='Dog' AND isEmpty=0;")) {
            if(qry.next()) {
                cagesNr = qry.value(0).toString().toStdString();
            }
        }
        mydb.close();
    }
    return cagesNr;
}

string Database::getNumbersOfFreeCages() {
    string cagesNr = "";

    if(!mydb.open()) {
        //Noe gikk galt..
    } else {
        QSqlQuery qry;

        if(qry.exec("SELECT COUNT(*) FROM Cages WHERE isEmpty=0;")) {
            if(qry.next()) {
                cagesNr = qry.value(0).toString().toStdString();
            }
        }

        mydb.close();
    }
    return cagesNr;
}

bool Database::checkFreeCatCages() {
    int cats = stoi(getNumbersOfFreeCatCages());

    if(cats > 0) {
        return true;
    }
    return false;
}

bool Database::checkFreeDogCages() {
    int dogs = stoi(getNumbersOfFreeDogCages());
    if(dogs > 0) {
        return true;
    }
    return false;
}

void Database::setCatInCage(int animalId) {
    if(!mydb.open()) {
        //Noe gikk galt..
    } else {
        QSqlQuery qry;
        qry.prepare("UPDATE Cages SET animalId= :aid, isEmpty=1 WHERE type='Cat' AND cageID="
                 "(SELECT cageID FROM Cages WHERE isEmpty=0 AND type='Cat' ORDER BY cageNr);");
        qry.bindValue(":aid", animalId);
        qry.exec();
        mydb.close();
    }
}

void Database::setDogInCage(int animalId) {
    if(!mydb.open()) {
        //Noe gikk galt..
    } else {
        QSqlQuery qry;
        qry.prepare("UPDATE Cages SET animalId= :aid, isEmpty=1 WHERE Type='Dog' AND cageID="
                    "(SELECT cageID FROM Cages WHERE isEmpty=0 AND type='Dog' ORDER BY cageNr);");
        qry.bindValue(":aid", animalId);
        qry.exec();
        mydb.close();
    }
}

void Database::removeAnimalFromCage(int animalId) {
    if(!mydb.open()) {
        //Noe gikk galt..
    } else {
        QSqlQuery qry;
        qry.prepare("UPDATE Cages SET animalId= NULL, isEmpty=0 WHERE animalId= :aid;");
        qry.bindValue(":aid", animalId);
        qry.exec();
        mydb.close();
    }
}

vector<string> Database::getPasswordInfo(string iusername){

    QSqlQuery qry;
    vector<string> returnable;
    qry.prepare("SELECT Password,Salt FROM Users WHERE Username = ?;");
    qry.bindValue(0, QString::fromStdString(iusername));

   if(qry.exec()) {
        if(qry.next()) {
            returnable.push_back(qry.value(0).toString().toStdString());
            returnable.push_back(qry.value(1).toString().toStdString());
            return returnable;
       }
   }
   return returnable;
}

bool Database::UserExists(string iusername){
    QSqlQuery qry;
    qry.prepare("SELECT Username FROM Users WHERE Username = ?;");
    qry.bindValue(0, QString::fromStdString(iusername));

    if(qry.exec()) {
         if(qry.next()) {
             return true;
        }
    }
    return false;
}
void Database::insertTemplateUsers(){
    string user1 = "admin";
    string salt1 = "aksdjilkepsa1";
    string password1 = hashPassword(salt1 + "admin");

    string user2 = "kritsi";
    string salt2 = "rtfvubkifsw2";
    string password2 = hashPassword(salt2 + "potet");

    string user3 = "marius";
    string salt3 = "s5drtyvghbåp3";
    string password3 = hashPassword(salt3 + "aubergine");


    insertUser("Administrator", user1 , password1 , salt1);
    insertUser("Kristine" , user2 , password2 , salt2);
    insertUser("Marius" , user3 , password3 , salt3);


    QMessageBox msgBox;
    msgBox.setText(QString::fromStdString(password1 + "  " + password2 + "  " + password3 +"  "));
    msgBox.exec();

}

void Database::insertUser(string iname, string iun, string ipass, string isalt){

    QSqlQuery qry;

    qry.prepare("INSERT INTO Users (name, username, salt, password) "
                "VALUES (?, ?, ?, ? )");
    qry.bindValue(0, QString::fromStdString(iname));
    qry.bindValue(1, QString::fromStdString(iun));
    qry.bindValue(2, QString::fromStdString(isalt));
    qry.bindValue(3, QString::fromStdString(ipass));
    qry.exec();

}
string Database::hashPassword(string password){
    hash<string> hash;
    size_t temp = hash(password);
    string hashoutput = to_string(temp);
    return hashoutput;
}

void Database::closeDB(){
    mydb.close();
}

void Database::initDB(QString path){
    initdb newdatabase;
    newdatabase.initDatabase(path);
}

bool Database::checkDB() {
    return mydb.open();
}

void Database::insertLogEntry(int animalid,QString message){
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
