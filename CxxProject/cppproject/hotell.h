#ifndef HOTELL_H
#define HOTELL_H
#include <iostream>
#include <vector>
#include "person.h"
#include "ansatt.h"
#include "kunde.h"
#include "animal.h"
#include "db.h"

using namespace std;

class Hotel {
public:
    Hotel();
    Hotel(string, int);
    void setName(string);
    string getName();
    void setCages(int);
    int getCages();
    void printHotel();
    void addEmployee(Employee);
    void removeEmployee(Employee);
    void checkIn(Animal);
    void checkOut(Animal);
    void addCustomer(Customer);
    void removeCustomer(Customer);
    string printEmployees();
    string printAnimals();
    string printCustomer();
    bool checkFreeCages(string animalType);

private:
    Database db;
    string name;
    int cages;

};

#endif // HOTELL_H
