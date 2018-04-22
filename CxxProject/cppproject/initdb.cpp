#include "initdb.h"
#include <QtSql>

initdb::initdb()
{

}

void initdb::initDatabase(QString path){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    db.open();

    initAnimals();
    initCages();
    initCageRows();
    initCustomer();
    initLog();
    initUsers();
    db.close();
}

void initdb::initAnimals(){
    QSqlQuery query;
    query.exec("CREATE TABLE `Animal` ("
               "`animalId`	INTEGER PRIMARY KEY AUTOINCREMENT,"
               "`name`	TEXT,"
               "`age`	INTEGER,"
               "`type`	TEXT,"
               "`isFemale`	INTEGER,"
               "`specialNeeds`	INTEGER,"
               "`specialNeedsText`	TEXT,`customerNr`	INTEGER,"
               "FOREIGN KEY(`customerNr`) REFERENCES `Customer`(`customerNr`) ON DELETE SET NULL);");
}




void initdb::initCustomer(){
    QSqlQuery query;
    query.exec("CREATE TABLE `Customer` ("
                  "`customerNr`	INTEGER PRIMARY KEY AUTOINCREMENT,"
                   "`firstname`	TEXT,"
                   "`lastname`	TEXT,"
                   "`tlfNr`	INTEGER);");
}


void initdb::initLog(){
    QSqlQuery query;
    query.exec("CREATE TABLE `Log` ("
               "`animalID`	INTEGER,"
               "`message`	TEXT,"
               "`timestamp`	TEXT,"
               "`LogID`	INTEGER PRIMARY KEY AUTOINCREMENT,"
               "FOREIGN KEY(`animalID`) REFERENCES `Animal`(`animalId`));"
               );
}


void initdb::initUsers(){
    QSqlQuery query;
    query.exec("CREATE TABLE `Users` ("
                   "`Name`	TEXT,"
                   "`Username`	TEXT,"
                  "`Salt`	TEXT,"
                   "`Password`	TEXT,"
                   "`Uid`	INTEGER PRIMARY KEY AUTOINCREMENT);");
}

void initdb::initCages(){
    QSqlQuery query;
    query.exec("CREATE TABLE `Cages` ("
                   "`cageID`	INTEGER PRIMARY KEY AUTOINCREMENT,"
                   "`cageNr`	INTEGER,"
                   "`animalID`	INTEGER,"
                   "`Type`	TEXT,"
                   "`isEmpty`	INTEGER,"
                   "FOREIGN KEY(`animalID`) REFERENCES `Animal`(`animalId`) ON DELETE SET NULL);"
               );
}

void initdb::initCageRows(){
    QSqlQuery qry;
    for(int i = 1; i <= 50; i++){
        qry.prepare("INSERT INTO Cages (cageNr, Type, isEmpty) VALUES (?, ?, 0 );");
        if(i<=25){
            qry.bindValue(0,i);
            qry.bindValue(1, QString::fromStdString("Cat"));
        } else {
            qry.bindValue(0,(i-25));
            qry.bindValue(1, QString::fromStdString("Dog"));
       }
        qry.exec();

    }
}
