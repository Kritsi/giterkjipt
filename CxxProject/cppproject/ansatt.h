#ifndef ANSATT_H
#define ANSATT_H

#include<iostream>

using namespace std;

class Employee: public Person {
public:
    Employee();
    Employee(string, string, int, string);
    void setAnsattNr(string);
    string getAnsattNr();

private:
    string ansattNr;
};

#endif // ANSATT_H
