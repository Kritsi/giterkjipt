#ifndef DOG_H
#define DOG_H

#include "animal.h"
#include "kunde.h"

class Dog: public Animal {
public:
    Dog();
    Dog(Customer, int, string, int, bool, bool);
};

#endif // DOG_H
