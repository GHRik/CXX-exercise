#ifndef CAT_HPP
#define CAT_HPP

#include "../utils.cpp"

class Cat : Animal
{
    public:
        Cat();
        virtual ~Cat();
        std::string sleep();
};

#endif // CAT_HPP
