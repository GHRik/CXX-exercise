#ifndef CAT_HPP
#define CAT_HPP

#include "utils.hpp"

class Cat : public Animal
{
    public:
        Cat();
        virtual ~Cat();
        std::string sleeping() override;
};

#endif // CAT_HPP
