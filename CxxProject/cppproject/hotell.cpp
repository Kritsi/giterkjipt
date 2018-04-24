#include <QCoreApplication>
#include <iostream>
#include <vector>
#include "hotell.h"
#include "db.h"

using namespace std;

Hotel::Hotel() {
    name = "";
}

Hotel::Hotel(string n, int nr) {
    name = n;
    cages = nr;
}

//Kan denne brukes?
bool Hotel::checkFreeCages(string animalType) {
    db.startDB();

    if(animalType == "Cat") {
        if(db.checkFreeCatCages()) {
            return false;
        }
    } else {
        if(db.checkFreeDogCages()) {
            return false;
        }
    }
    return false;
}

void Hotel::printHotel() {
    cout << name << " " << cages << endl;
}

void Hotel::setName(string n) {
    name = n;
}

string Hotel::getName() {
    return name;
}

void Hotel::setCages(int nr) {
    cages = nr;
}

int Hotel::getCages() {
    return cages;
}

