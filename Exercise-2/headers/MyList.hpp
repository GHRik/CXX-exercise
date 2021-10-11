#ifndef MYLIST_HPP
#define MYLIST_HPP

#include "utils.hpp"

template <typename T>
class MyList
{
    public:
        MyList();
        virtual ~MyList();
        unsigned int getSize();
        utils::RESULT_CODE back_push(T object);
        utils::RESULT_CODE front_push(T object);
        utils::RESULT_CODE front_pop();
        utils::RESULT_CODE back_pop();
        utils::RESULT_CODE insert_to_list(unsigned int element, T object);
        utils::RESULT_CODE printAll();
        utils::RESULT_CODE clear_list();
        T getElement(unsigned int element);
        bool isEmpty();

    private:
        unsigned int list_size;

};

#endif // MYLIST_HPP
