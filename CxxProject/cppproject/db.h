#ifndef DB_H
#define DB_H

#include "kunde.h"
#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <iostream>
#include <vector>

using namespace std;

class Database {
public:
    Database();
    void startDB();
    QSqlDatabase getMydb();
    void insertCustomer(string firstname, string lastname, int tlfNr);
    void insertAnimal(Customer owner, string name, int age, string type, bool isFemale, bool specialNeeds);
    void deleteAnimal(int tlfNr, string animalName);
    void addSpecialNeeds(Customer owner, string animalName, string specialNeedsText);
    Customer createCustomer(int tlf);
    bool searchCustomer(int tlf);
    int getAnimalId(int tlfNr, string animalName);
    string getAnimalAge(int animalId);
    string getAnimalOwner(int animalId);
    string getAnimalType(int animalId);
    string getAnimalSex(int animalId);
    string getAnimalNeeds(int animalId);
    string getNumbersOfCages();
    string getNumbersOfCatCages();
    string getNumbersOfDogCages();
    string getNumbersOfFreeCages();
    string getNumbersOfFreeCatCages();
    string getNumbersOfFreeDogCages();
    bool checkFreeCatCages();
    bool checkFreeDogCages();
    void setCatInCage(int animalId);
    void setDogInCage(int animalId);
    vector<string> getPasswordInfo(string iusername);
    bool UserExists(string iusername);
    void insertTemplateUsers();
    void insertUser(string iname, string iun, string ipass, string isalt);
    string hashPassword(string password);
    void insertLogEntry(int animalID, QString message);
    bool checkDB();
    void initDB(QString path);
    void closeDB();
private:
    QSqlDatabase mydb;
};

#endif // DB_H
