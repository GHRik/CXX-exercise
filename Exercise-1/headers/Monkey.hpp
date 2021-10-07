#ifndef MONKEY_HPP
#define MONKEY_HPP

#include "utils.hpp"

class Monkey : public Animal
{
    public:
        Monkey();
        virtual ~Monkey();
        std::string sleeping() override;
};

#endif // MONKEY_HPP
