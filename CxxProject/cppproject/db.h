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
    void insertCustomer(QString firstname, QString lastname, int tlfNr);
    void insertAnimal(Customer owner, QString name, int age, QString type, bool isFemale, bool specialNeeds);
    void deleteAnimal(int tlfNr, QString animalName);
    void addSpecialNeeds(Customer owner, QString animalName, QString specialNeedsText);
    Customer createCustomer(int tlf);
    bool searchCustomer(int tlf);
<<<<<<< HEAD
    int getAnimalId(int tlfNr, string animalName);
    string getAnimalAge(int animalId);
    string getAnimalOwner(int animalId);
    string getAnimalType(int animalId);
    string getAnimalSex(int animalId);
    string getAnimalNeeds(int animalId);
    string getAnimalCheckInDate(int animalId);
    string getNumbersOfCages();
    string getNumbersOfCatCages();
    string getNumbersOfDogCages();
    string getNumbersOfFreeCages();
    string getNumbersOfFreeCatCages();
    string getNumbersOfFreeDogCages();
=======
    void setAnimalPic(int animalid, QString path);
    void insertAnimalPic(int animalid, QString path);
    QString getAnimalPic(int animalid);
    int getAnimalId(int tlfNr, QString animalName);
    int getAnimalAge(int animalId);
    QString getAnimalOwner(int animalId);
    QString getAnimalType(int animalId);
    QString getAnimalSex(int animalId);
    QString getAnimalNeeds(int animalId);
    int getNumbersOfCages();
    int getNumbersOfCatCages();
    int getNumbersOfDogCages();
    int getNumbersOfFreeCages();
    int getNumbersOfFreeCatCages();
    int getNumbersOfFreeDogCages();
>>>>>>> master
    bool checkFreeCatCages();
    bool checkFreeDogCages();
    void setCatInCage(int animalId);
    void setDogInCage(int animalId);
    void removeAnimalFromCage(int animalId);
    vector<string> getPasswordInfo(QString iusername);
    bool UserExists(QString iusername);
    void insertTemplateUsers();
    void insertUser(QString iname, QString iun, QString ipass, QString isalt);
    string hashPassword(string password);
    void insertLogEntry(int animalID, QString message);
    bool checkDB();
    void initDB(QString path);
    void closeDB();
private:
    QSqlDatabase mydb;
};

#endif // DB_H
