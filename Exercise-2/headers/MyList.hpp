#ifndef MYLIST_HPP
#define MYLIST_HPP

#include "utils.hpp"
#include <memory>
#include <iostream>
#include <climits>
#include <exception>

template <typename T>
struct Node
{
    Node(){}

    T value;
    std::shared_ptr<Node<T>> next_node;
};

template <typename T>
class MyList
{
    public:
        MyList();
        virtual ~MyList() = default;
        size_t getSize();
        utils::RESULT_CODE back_push(T object);
        utils::RESULT_CODE front_push(T object);
        utils::RESULT_CODE front_pop();
        utils::RESULT_CODE back_pop();
        utils::RESULT_CODE insert_to_list(unsigned int element, T object);
        utils::RESULT_CODE printAll();
        utils::RESULT_CODE clear_list();
        std::shared_ptr<Node<T>> getElement(unsigned int element);
        bool isEmpty();

    private:
        size_t list_size;
        std::shared_ptr<Node<T>> head;
        std::shared_ptr<Node<T>> tail;
};

#endif // MYLIST_HPP
