#ifndef PERSON_H
#define PERSON_H
#include <iostream>

using namespace std;

class Person {
public:
    Person();
    Person(string fn, string ln, int a);
    string printInfo();
    void setFirstName(string);
    string getFirstName();
    void setLastName(string);
    string getLastName();
    void setAge(int);
    int getAge();
    void setTlfNr(string);
    string getTlfNr();
    void setBirthDate(string);
    string getBirthDate();

protected:
    string firstname;
    string lastname;
    int age;
    string tlfNr;
    string birthDate;
};

#endif // PERSON_H
