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


void initdb::initCages(){
    QSqlQuery query;
    query.exec("CREATE TABLE `Cages` ("
                   "`cageID`	INTEGER PRIMARY KEY AUTOINCREMENT,"
                   "`cageNr`	INTEGER,"
                   "`animalID`	INTEGER,"
                   "`Type`	TEXT,"
                   "FOREIGN KEY(`animalID`) REFERENCES `Animal`(`animalId`) ON DELETE SET NULL);"
               );
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
        "FOREIGN KEY(`animalID`) REFERENCES `Animal`(`animalId`),"
        "PRIMARY KEY(`animalID`));");
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
