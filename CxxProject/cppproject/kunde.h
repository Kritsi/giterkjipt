#ifndef KUNDE_H
#define KUNDE_H
#include "person.h"
#include<iostream>

using namespace std;

class Customer: public Person {
public:
    Customer();
    Customer(string ifristname, string ilastname, string itelephone);
    void setKundeNr(int);
    int getKundeNr();

private:
    int kundeNr;
};

#endif // KUNDE_H
