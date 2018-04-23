#ifndef HOTELL_H
#define HOTELL_H
#include <iostream>
#include <vector>
#include "person.h"
#include "ansatt.h"
#include "kunde.h"
#include "animal.h"

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
    string name;
    int cages;
    vector<Employee> employees;
    vector<Customer> customers;
    vector<Animal> animals;
};

#endif // HOTELL_H
