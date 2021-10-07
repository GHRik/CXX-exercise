#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal
{
    public:
        Animal();
        virtual ~Animal();
        virtual std::string sleeping() = 0;
};

#endif // ANIMAL_H
