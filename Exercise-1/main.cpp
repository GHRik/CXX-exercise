#include <iostream>
#include "headers/Cat.hpp"
#include "headers/Dog.hpp"
#include "headers/Monkey.hpp"
#include "headers/Interfaces/Animal.hpp"
#include <vector>
#include <memory>

int main()
{
    /*
    shared_ptr - can be copied and moved.
    unique_ptr - can be moves, CANT be copied.
    auto_ptr - old unique_ptr , not secured
    weake_ptr - copied of shared_ptr , but he must be used with shared_ptr.
    https://www.geeksforgeeks.org/auto_ptr-unique_ptr-shared_ptr-weak_ptr-2/
    */
    std::shared_ptr<Animal> cat(new Cat());
    std::shared_ptr<Animal> dog(new Dog());
    std::shared_ptr<Animal> monkey(new Monkey());

    std::vector<std::shared_ptr<Animal>> myAnimals;
    myAnimals.push_back(cat);
    myAnimals.push_back(dog);
    myAnimals.push_back(monkey);

    for(unsigned int i=0; i<myAnimals.size(); ++i){
        std::cout << myAnimals.at(i).get()->sleeping() << std::endl;
    }

    return 0;
}
