#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <QString>
using namespace std;

class Person {
public:
    Person();
    Person(QString fn, QString ln, int a);
    QString printInfo();
    void setFirstName(QString);
    QString getFirstName();
    void setLastName(QString);
    QString getLastName();
    void setAge(int);
    int getAge();
    void setTlfNr(int);
    int getTlfNr();
    void setBirthDate(QString);
    QString getBirthDate();
    bool checkName(string iname);
    bool checkTlfNr(string tlfNr);
    //bool checkAllInput(string, ifirstname, ilastname, itlf, iname, iage);

protected:
    QString firstname;
    QString lastname;
    int age;
    int tlfNr;
    QString birthDate;
};

#endif // PERSON_H
