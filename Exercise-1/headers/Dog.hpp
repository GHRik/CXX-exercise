#ifndef DOG_HPP
#define DOG_HPP

#include "../utils.cpp"

class Dog : public Animal
{
    public:
        Dog();
        virtual ~Dog();
        std::string sleep();
};

#endif // DOG_HPP
