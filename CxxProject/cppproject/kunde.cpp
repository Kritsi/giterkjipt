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
    tlfNr = "";
}

Customer::Customer(string fn, string ln, string t) {
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
