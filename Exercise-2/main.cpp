#include <iostream>
#include "headers/MyList_template.hpp"
#include <string>

using namespace std;


struct Noise
{
    Noise() {{std::cout << "Noise()" << std::endl;}}
    Noise(const Noise& other) {std::cout << "Noise(const Noise& other)" << std::endl;}
    Noise(const Noise&& other) {std::cout << "Noise(const Noise&& other)" << std::endl;}
    ~Noise() {std::cout << "~Noise()"<<std::endl;}

    Noise& operator=(const Noise& other) {std::cout << "Noise& operator=(const Noise& other)" << std::endl; return *this;}
    Noise& operator=(const Noise&& other) {std::cout << "Noise& operator=(const Noise&& other)" << std::endl; return *this;}
};

class ExampleClass
{
    public:
        explicit ExampleClass( int value ): m_value(value)
        {
            m_value = value;
        }
        ExampleClass(){}
        int m_value;

};

int main()
{
    MyList<int> myList;
    myList.back_push(5);
    myList.back_push(6);
    myList.back_push(6);
    myList.back_push(6);
    myList.back_push(6);
    myList.back_push(6);
    myList.back_push(6);
    myList.front_pop();
    myList.front_pop();
    myList.front_pop();
    myList.front_pop();
    myList.front_pop();
    myList.front_pop();
    myList.front_pop();
    myList.front_pop();
    myList.clear_list();


    return 0;
}
