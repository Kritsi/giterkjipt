#include <QCoreApplication>
#include <iostream>
#include "person.h"
#include <regex>

using namespace std;

Person::Person() {
    firstname = "";
    lastname = "";
    age = 0;
}

Person::Person(QString fn, QString ln, int a) {
    firstname = fn;
    lastname = ln;
    age = a;
}

QString Person::printInfo() {
    return firstname + " " + lastname + " " + tlfNr;
}

bool Person::checkName(string iname) {
    regex reg("^[a-zæøåA-ZÆØÅ -]+$");
    if(regex_match(iname, reg)) {
        return true;
    }
    return false;
}

bool Person::checkTlfNr(string tlfNr) {
    regex reg("^[0-9]{8}$");
    if(regex_match(tlfNr, reg)) {
        return true;
    }
    return false;
}

void Person::setFirstName(QString fn) {
    firstname = fn;
}

QString Person::getFirstName() {
    return firstname;
}

void Person::setLastName(QString ln) {
    lastname = ln;
}

QString Person::getLastName() {
    return lastname;
}

void Person::setAge(int a) {
    age = a;
}

int Person::getAge() {
    return age;
}

void Person::setTlfNr(int nr) {
    tlfNr = nr;
}

int Person::getTlfNr() {
    return tlfNr;
}

void Person::setBirthDate(QString b) {
    birthDate = b;
}

QString Person::getBirthDate() {
    return birthDate;
}
