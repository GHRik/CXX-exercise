#ifndef MYLIST_HPP
#define MYLIST_HPP

#include "utils.hpp"
#include <memory>
#include <iostream>
#include <climits>
#include <exception>

/** \brief Node structure
 *  Template of Node. Is a part of LinkedList.
 *  If you want to know how to linked list works
 *  Please visit:
 *  https://www.geeksforgeeks.org/data-structures/linked-list/
 * \param next_node - pointer on next Node in linkedList
 * \param value - value of storage object.
 *
 */

template <typename T>
struct Node
{
    Node(){}

    T value;
    std::shared_ptr<Node<T>> next_node;
};

/** \brief MyList
 *  It is complex of nodes which point of each other
 *  If you want to know how linked list works
 *  Please visit:
 *  https://www.geeksforgeeks.org/data-structures/linked-list/
 */


template <typename T>
class MyList
{
    public:
        MyList();
        virtual ~MyList() = default;

        /** \brief getSize
         *  Function which return a size of
         *  object liked list.
         * \return size of object liked list
         *
         */
        const size_t getSize() const;

        /** \brief push_back
         *  This function take a object and insert
         *  this object on the end of linked list.
         *  This function will throw if size UINT_MAX
         *  will be achieved.
         * \param T object - object to push
         * \return RESULT_CODE - OK if finally pushed
         *  NULLPTR_EXCEPTION - if nullptr was called
         *  OUT_OF_BOUND - if UINT_MAX is size.
         *
         */
        const utils::RESULT_CODE back_push(T const & object);

        /** \brief push_back
         *  This function take a object and insert
         *  this object on the first element
         *  of linked list.
         *  This function will throw if size UINT_MAX
         *  will be achieved.
         * \param T object - object to push
         * \return RESULT_CODE - OK if finally pushed
         *  NULLPTR_EXCEPTION - if nullptr was called
         *  OUT_OF_BOUND - if UINT_MAX is size.
         *
         */
        const utils::RESULT_CODE front_push(T const & object);

        /** \brief front_pop
         *  This function remove first object of the
         *  linked list.
         * \return RESULT_CODE - OK if finally poped
         *  NULLPTR_EXCEPTION - if nullptr was called
         *  OUT_OF_BOUND - if pop on empty list.
         *
         */
        const utils::RESULT_CODE front_pop();

        /** \brief front_pop
         *  This function remove last object of the
         *  linked list.
         * \return RESULT_CODE - OK if finally poped
         *  NULLPTR_EXCEPTION - if nullptr was called
         *  OUT_OF_BOUND - if pop on empty list.
         *
         */
        const utils::RESULT_CODE back_pop();

        /** \brief insert function
         *  With this function you can insert object on
         *  nth(element) place in linked list. You can
         *  use this function to place object on last
         *  place. For example if your list is size 6.
         *  you can use this function to place object
         *  on place number 7.
         * \param element - nth place in linked list.
         * \param object - object to insert.
         * \return RESULT_CODE - OK if finally insert
         *  NULLPTR_EXCEPTION - if nullptr was called
         *  OUT_OF_BOUND - if nth place is size+1 or
         *  smaller than 0.
         */
        const utils::RESULT_CODE insert_to_list(const unsigned int & element, const T &object);

        /** \brief printAll
         *  With printAll function you can print all
         *  object you have storage in list. Remember
         *  if you want to print your own class/struct
         *  you have to overload << operator.
         * \return RESULT_CODE - OK if finally print
         *  NULLPTR_EXCEPTION - if nullptr was called
         *
         */
        const utils::RESULT_CODE printAll() const;

        /** \brief clear
         *  If you want to delete all object which
         *  you are storage in list. You can use this
         *  function. After run this function. getSize()
         *  will return 0.
         * \return RESULT_CODE - OK if finally clear
         *
         */
        const utils::RESULT_CODE clear_list();

        /** \brief getElement
         *  With this function you can get pointer on
         *  nth element. Remember this is linked list
         *  and this operation will be very slow, because
         *  if you want a nth element function will loop
         *  over nth-1 element of your list. Function can
         *  throw out_of range if you try to get element
         *  out of the list size.
         * \param nth element - element which you want.
         * \return RESULT_CODE - OK if finally get element
         *  NULLPTR_EXCEPTION - if nullptr was called
         *
         */
        const std::shared_ptr<Node<T>> getElement(const unsigned int & element) const;

        /** \brief isEmpty
         *  Function will check if linked list
         * is empty or not.
         * \return true if empty,
         *  false if not empty
         *
         */
        const bool isEmpty() const;

    private:
        size_t list_size;
        std::shared_ptr<Node<T>> head;
        std::shared_ptr<Node<T>> tail;
};

#endif // MYLIST_HPP
