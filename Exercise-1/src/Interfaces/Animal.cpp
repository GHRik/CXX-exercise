#include "../../headers/Interfaces/Animal.hpp"

Animal::Animal()
{
    //ctor
}

Animal::~Animal()
{
    //dtor
}

void Animal::crash()
{
    throw 5;
}
