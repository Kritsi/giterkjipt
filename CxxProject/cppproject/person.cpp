#include <QCoreApplication>
#include <iostream>
#include "person.h"

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
