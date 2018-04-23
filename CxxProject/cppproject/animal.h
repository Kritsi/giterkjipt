#ifndef ANIMAL_H
#define ANIMAL_H
#include "kunde.h"
#include<iostream>

using namespace std;

class Animal {
public:
    Animal();
   // Animal(Customer, string, string, int, string, bool, bool);
    void setName(string);
    string getName();
    void setAge(int);
    int getAge();
    void setType(string);
    string getType();
    void setSex(bool);
    bool getSex();
    void setSpecialNeeds(bool);
    bool getSpecialNeeds();
    void setId(int);
    int getId();
    void setCustomer();
    Customer getCustomer();
    string printAnimal();
    bool checkName(string iname);
    bool checkAge(string iage);

protected:
    int id;
    string name;
    int age;
    string type;
    bool isFemale;
    bool specialNeeds;
    Customer owner;
};

#endif // ANIMAL_H
