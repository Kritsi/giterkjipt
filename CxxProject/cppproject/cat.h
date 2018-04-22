#ifndef CAT_H
#define CAT_H

#include "animal.h"
#include "kunde.h"

class Cat: public Animal {
public:
    Cat();
    Cat(Customer owner, int id, string name, int age, bool isFemale, bool specialNeeds);
};

#endif // CAT_H
