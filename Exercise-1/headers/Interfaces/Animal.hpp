#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

class Animal
{
    public:
        Animal();
        virtual ~Animal();
        virtual std::string sleeping() = 0;
        void crash();
};

#endif // ANIMAL_H
