#ifndef ANSATT_H
#define ANSATT_H

#include<iostream>

using namespace std;

class Employee: public Person {
public:
    Employee();
    Employee(QString firstname, QString lastname, int age, int ansattNr);
    void setAnsattNr(string);
    int getAnsattNr();

private:
    int ansattNr;
};

#endif // ANSATT_H
