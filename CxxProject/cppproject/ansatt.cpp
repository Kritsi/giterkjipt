#include <QCoreApplication>
#include <iostream>
#include <regex>
#include "person.h"
#include "ansatt.h"

using namespace std;

Employee::Employee() {
    firstname = "";
    lastname = "";
    age = 0;
    ansattNr = 0;
}

Employee::Employee(QString fn, QString ln, int a, int aNr) {
    firstname = fn;
    lastname = ln;
    age = a;
    ansattNr = aNr;
}

void Employee::setAnsattNr(string nr) {
    regex reg("^[0-9]{8}$");
    if(regex_match(nr, reg)) {
        ansattNr = stoi(nr);
        cout << "Vellyket oppdatering!" << endl;
    } else {
        cout << "Ikke gyldig ansattNr, oppdatering mislykket!" << endl;
    }
}

int Employee::getAnsattNr() {
    return ansattNr;
}
