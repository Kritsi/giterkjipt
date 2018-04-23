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

Person::Person(string fn, string ln, int a) {
    firstname = fn;
    lastname = ln;
    age = a;
}

string Person::printInfo() {
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

void Person::setFirstName(string fn) {
    firstname = fn;
}

string Person::getFirstName() {
    return firstname;
}

void Person::setLastName(string ln) {
    lastname = ln;
}

string Person::getLastName() {
    return lastname;
}

void Person::setAge(int a) {
    age = a;
}

int Person::getAge() {
    return age;
}

void Person::setTlfNr(string nr) {
    tlfNr = nr;
}

string Person::getTlfNr() {
    return tlfNr;
}

void Person::setBirthDate(string b) {
    birthDate = b;
}

string Person::getBirthDate() {
    return birthDate;
}
