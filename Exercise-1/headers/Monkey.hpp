#ifndef MONKEY_HPP
#define MONKEY_HPP

#include "../utils.cpp"

class Monkey:public Animal
{
    public:
        Monkey();
        virtual ~Monkey();
        std::string sleep();
};

#endif // MONKEY_HPP
