#ifndef CAT_HPP
#define CAT_HPP

#include "utils.hpp"

class Cat : Animal
{
    public:
        Cat();
        virtual ~Cat();
        std::string sleeping();
};

#endif // CAT_HPP
