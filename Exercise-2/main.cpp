#include <iostream>
#include "headers/MyList_template.hpp"

using namespace std;

int main()
{
         MyList<int> myList;
    myList.back_push(1);
    myList.back_push(2);
    myList.back_push(3);
    myList.back_push(4);
    myList.back_push(5);
    myList.back_push(6);
    myList.back_pop();
    myList.printAll();

    return 0;
}
