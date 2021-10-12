#include <iostream>
#include "headers/MyList_template.hpp"
#include <string>

using namespace std;

class MockClass
{
    public:
        MockClass( int value ): m_value(value){}
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
    std::cout << myList.getElement(3).m_value;

    return 0;
}
