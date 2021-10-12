#include "MyList.hpp"

template <typename T>
MyList<T>::MyList() : list_size(0), head(nullptr), tail(nullptr)
{
    //ctor
}

template <typename T>
unsigned int MyList<T>::getSize()
{
    return MyList<T>::list_size;
}

template<typename T>
utils::RESULT_CODE MyList<T>::back_push(T object)
{
    std::shared_ptr<Node<T>> newElement( new Node<T> );
    newElement.get()->next_node = nullptr;
    newElement.get()->value = object;

    if (MyList::head == nullptr)
    {
        MyList::head = newElement;
        MyList::tail = newElement;
    }
    MyList::tail.get()->next_node = newElement;
    MyList::tail = newElement;

    if(list_size == UINT_MAX-1)
    {
        return utils::RESULT_CODE::OUT_OF_BOUND;
    }
    else
    {
      MyList::list_size = MyList::list_size+1;
    }

    return utils::RESULT_CODE::OK;
}

template<typename T>
utils::RESULT_CODE MyList<T>::front_push(T object)
{
    if( MyList::isEmpty() == true )
    {
        return MyList::back_push(object);
    }
    std::shared_ptr<Node<T>> newElement( new Node<T> );
    newElement.get()->next_node = MyList::head;
    newElement.get()->value = object;

    MyList::head = newElement;

    if(list_size == UINT_MAX-1)
    {
        return utils::RESULT_CODE::OUT_OF_BOUND;
    }
    else
    {
      MyList::list_size = MyList::list_size+1;
    }

    return utils::RESULT_CODE::UNKNOWN_ERROR;
}

template<typename T>
utils::RESULT_CODE MyList<T>::front_pop()
{
    if (MyList::isEmpty() == true)
    {
        return utils::RESULT_CODE::OUT_OF_BOUND;
    }
    std::shared_ptr<Node<T>> temp = head.get()->next_node;
    head = temp;

    MyList::list_size = MyList::list_size-1;
    return utils::RESULT_CODE::UNKNOWN_ERROR;
}

template<typename T>
utils::RESULT_CODE MyList<T>::back_pop()
{
    if (MyList::isEmpty() == true)
    {
        return utils::RESULT_CODE::OUT_OF_BOUND;
    }
    std::shared_ptr<Node<T>> ptrOnElem = MyList::head;
    if( MyList::head == nullptr )
    {
        return utils::RESULT_CODE::NULLPTR_CALLED;
    }
    for( unsigned int i = 1; i < MyList::getSize()-1; ++i)
    {
        if( ptrOnElem == nullptr )
        {
            return utils::RESULT_CODE::NULLPTR_CALLED;
        }
        ptrOnElem = ptrOnElem.get()->next_node;
    }
    tail = ptrOnElem;

    MyList::list_size = MyList::list_size-1;
    return utils::RESULT_CODE::OK;
}

template<typename T>
utils::RESULT_CODE MyList<T>::insert_to_list(unsigned int ,T object)
{
    return utils::RESULT_CODE::UNKNOWN_ERROR;
}

template<typename T>
utils::RESULT_CODE MyList<T>::printAll()
{
    std::shared_ptr<Node<T>> temp = MyList::head;
    if (MyList::head == nullptr)
    {
        return utils::RESULT_CODE::NULLPTR_CALLED;
    }
    while( temp.get()->next_node != MyList::tail.get()->next_node )
    {
        if( temp == nullptr )
        {
            return utils::RESULT_CODE::NULLPTR_CALLED;
        }
        std::cout<<temp.get()->value;
        temp = temp.get()->next_node;
    }
    std::cout << tail.get()->value;
    return utils::RESULT_CODE::OK;
}

template<typename T>
utils::RESULT_CODE MyList<T>::clear_list()
{
    MyList::head = nullptr;
    MyList::tail = nullptr;
    MyList::list_size = 0;
    return utils::RESULT_CODE::OK;
}

template<typename T>
T MyList<T>::getElement(unsigned int element)
{
    if (element >= MyList::getSize())
    {
        throw utils::RESULT_CODE::OUT_OF_BOUND;
    }
    T value;
    std::shared_ptr<Node<T>> temp = MyList::head;
    if( MyList::head == nullptr )
    {
        return utils::RESULT_CODE::NULLPTR_CALLED;
    }
    for( unsigned int i = 0; i <= element; ++i)
    {
        if( temp == nullptr )
        {
            throw utils::RESULT_CODE::NULLPTR_CALLED;
        }
        value = temp.get()->value;
        temp = temp.get()->next_node;
    }
    return value;

}

template<typename T>
bool MyList<T>::isEmpty()
{
    if (MyList<T>::getSize() == 0)
    {
        return true;
    }
    return false;
}
