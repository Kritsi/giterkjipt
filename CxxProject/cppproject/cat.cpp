#include <QCoreApplication>
#include <iostream>
#include <regex>
#include "animal.h"
#include "cat.h"
#include "kunde.h"

using namespace std;

Cat::Cat() {
    name = "Cat";
    age = 0;
    type = "Cat";
    isFemale = false;
    specialNeeds = false;
}

Cat::Cat(Customer iowner, int iid, string iname, int iage, bool iisFemale, bool ispecialNeeds) {
    owner = iowner;
    id = iid;
    name = iname;
    age = iage;
    type = "Cat";
    isFemale = iisFemale;
    specialNeeds = ispecialNeeds;
}
