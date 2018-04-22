#include <QCoreApplication>
#include <iostream>
#include <regex>
#include "animal.h"
#include "dog.h"

using namespace std;

Dog::Dog() {
    name = "Dog";
    age = 0;
    type = "Dog";
    isFemale = false;
    specialNeeds = false;
}

Dog::Dog(Customer iowner, int iid, string iname, int iage, bool iisFemale, bool ispecialNeeds) {
    owner = iowner;
    id = iid;
    name = iname;
    age = iage;
    type = "Dog";
    isFemale = iisFemale;
    specialNeeds = ispecialNeeds;
}
