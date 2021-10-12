#include <iostream>
#include "headers/MyList_template.hpp"
#include <string>

using namespace std;

class MockClass
{
    public:
        MockClass( int value ): m_value(value){}
        MockClass(){}
        int m_value;

};

int main()
{

    MockClass mock1(1);
    MockClass mock2(2);
    MockClass mock3(3);
    MockClass mock4(4);
    MyList<MockClass> myList;

    myList.back_push(mock1);
    myList.back_push(mock2);
    myList.back_push(mock3);
    myList.insert_to_list(3,mock4);
    std::cout << myList.getElement(0).get()->value.m_value;

    MyList<int> myListInt;
    myListInt.back_push(1);
    myListInt.back_push(2);
    myListInt.back_push(3);
    myListInt.back_push(4);
    myListInt.back_push(5);
    myListInt.insert_to_list(3,3);
    std::cout << myListInt.getElement(3).get()->value;


    return 0;
}
