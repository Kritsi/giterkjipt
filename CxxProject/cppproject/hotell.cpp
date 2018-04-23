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
    Database mydb;
    mydb.startDB();

    if(animalType == "Cat") {
        if(mydb.checkFreeCatCages()) {
            return false;
        }
    } else {
        if(mydb.checkFreeDogCages()) {
            return false;
        }
    }
    return false;
}

void Hotel::printHotel() {
    cout << name << " " << cages << endl;
}

void Hotel::addEmployee(Employee e) {
    employees.push_back(e);
}

void Hotel::removeEmployee(Employee e) {
    string employeeNr = e.getAnsattNr();

    for(int unsigned i = 0; i < employees.size(); i++) {
        if(employees[i].getAnsattNr() == employeeNr) {
            employees.erase(employees.begin() + i);
            cout << e.getFirstName() << " slettet!" << endl;
            break;
        }
    }
}

void Hotel::checkIn(Animal a) {
    animals.push_back(a);
}

void Hotel::checkOut(Animal a) {
    int idNr = a.getId();

    for(int unsigned i = 0; i < animals.size(); i++) {
        if(animals[i].getId() == idNr) {
            animals.erase(animals.begin() + i);
            cout << a.getName() << " er slettet!" << endl;
            break;
        }
    }
}

void Hotel::addCustomer(Customer c) {
    customers.push_back(c);
}

void Hotel::removeCustomer(Customer c) {
    int customerNr = c.getKundeNr();

    for(int unsigned i = 0; i < customers.size(); i++) {
        if(customers[i].getKundeNr() == customerNr) {
            customers.erase(customers.begin() + i);
            cout << c.getFirstName() << " er slettet!" << endl;
            break;
        }
    }
}

string Hotel::printEmployees() {
    string printEmp = "";
    for(int unsigned i = 0; i < employees.size(); i++) {
        printEmp += employees[i].getFirstName() + " ";
    }
    return printEmp;
}

string Hotel::printAnimals() {
    string printAn = "";
    for(int unsigned i = 0; i < animals.size(); i++) {
        printAn += animals[i].getName() + " ";
    }
    return printAn;
}

string Hotel::printCustomer() {
    string printCo = "";
    for(int unsigned i = 0; i < animals.size(); i++) {
        printCo += customers[i].getFirstName() + " " + customers[i].getLastName() + " ";
    }
    return printCo;
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

