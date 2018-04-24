#include <QCoreApplication>
#include <iostream>
#include <regex>
#include "person.h"
#include "kunde.h"

Customer::Customer() {
    firstname = "";
    lastname = "";
    age = 0;
    kundeNr = 0;
    tlfNr = 0;
}

Customer::Customer(QString fn, QString ln, int t) {
    firstname = fn;
    lastname = ln;
    tlfNr = t;
    age = 0;
}

void Customer::setKundeNr(int nr) {
    kundeNr = nr;
}

int Customer::getKundeNr() {
    return kundeNr;
}
