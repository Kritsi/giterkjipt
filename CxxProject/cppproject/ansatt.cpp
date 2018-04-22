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
    ansattNr = "";
}

Employee::Employee(string fn, string ln, int a, string aNr) {
    firstname = fn;
    lastname = ln;
    age = a;
    ansattNr = aNr;
}

void Employee::setAnsattNr(string nr) {
    regex reg("^[0-9]{8}$");
    if(regex_match(nr, reg)) {
        ansattNr = nr;
        cout << "Vellyket oppdatering!" << endl;
    } else {
        cout << "Ikke gyldig ansattNr, oppdatering mislykket!" << endl;
    }
}

string Employee::getAnsattNr() {
    return ansattNr;
}
