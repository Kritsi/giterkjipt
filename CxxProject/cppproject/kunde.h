#ifndef KUNDE_H
#define KUNDE_H
#include "person.h"
#include <iostream>
#include <QString>

using namespace std;

class Customer: public Person {
public:
    Customer();
    Customer(QString ifirstname, QString ilastname, int itelephone);
    void setKundeNr(int);
    int getKundeNr();

private:
    int kundeNr;
};

#endif // KUNDE_H
