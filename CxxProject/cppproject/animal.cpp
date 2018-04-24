#include <QCoreApplication>
#include <iostream>
#include <regex>
#include "animal.h"

using namespace std;

Animal::Animal() {
    name = "";
    age = 0;
    type = "";
    isFemale = "";
    specialNeeds = false;
}


bool Animal::checkName(string iname) {
    regex reg("^[a-zæøåA-ZÆØÅ ]+$");
    if(regex_match(iname, reg)) {
        return true;
    }
    return false;
}

bool Animal::checkAge(string iage) {
    regex reg("^[0-9]+$");
    if(regex_match(iage, reg)) {
        return true;
    }
    return false;
}

void Animal::setName(string n) {
    name = n;
}

string Animal::getName() {
    return name;
}

void Animal::setAge(int a) {
    age = a;
}

int Animal::getAge() {
    return age;
}

void Animal::setSex(bool s) {
    isFemale = s;
}

bool Animal::getSex() {
    return isFemale;
}

void Animal::setType(string t) {
    type = t;
}

string Animal::getType() {
    return type;
}

void Animal::setSpecialNeeds(bool s) {
    specialNeeds = s;
}

bool Animal::getSpecialNeeds() {
    return specialNeeds;
}

void Animal::setId(int i) {
    id = i;
}

int Animal::getId() {
    return id;
}

