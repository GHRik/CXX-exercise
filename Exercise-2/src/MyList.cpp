#include "MyList.hpp"

template <typename T>
MyList<T>::MyList() : list_size(0), head(nullptr), tail(nullptr)
{
    //ctor
}

template <typename T>
const size_t MyList<T>::getSize() const
{
    return MyList<T>::list_size;
}

template<typename T>
const utils::RESULT_CODE MyList<T>::back_push(T const & object)
{
    auto newElement = std::make_shared<Node<T>>();
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
const utils::RESULT_CODE MyList<T>::front_push(T const & object)
{
    if( MyList::isEmpty() == true )
    {
        return MyList::back_push(object);
    }
    auto newElement = std::make_shared<Node<T>>();
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

    return utils::RESULT_CODE::OK;
}

template<typename T>
const utils::RESULT_CODE MyList<T>::front_pop()
{
    if (MyList::isEmpty() == true)
    {
        return utils::RESULT_CODE::OUT_OF_BOUND;
    }
    std::shared_ptr<Node<T>> temp = head.get()->next_node;
    head = temp;

    MyList::list_size = MyList::list_size-1;
    return utils::RESULT_CODE::OK;
}

template<typename T>
const utils::RESULT_CODE MyList<T>::back_pop()
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
const utils::RESULT_CODE MyList<T>::insert_to_list(const unsigned int & element, const T & object)
{
    if(element > MyList::getSize())
    {
        throw std::out_of_range("");
    }
    else if(element == 0)
    {
        return MyList::front_push(object);
    }
    else if(element == MyList::getSize())
    {
        return MyList::back_push(object);
    }
    else
    {
        auto newElement = std::make_shared<Node<T>>();;
        newElement.get()->next_node = nullptr;
        newElement.get()->value = object;

        std::shared_ptr<Node<T>> temp = head;
        for(unsigned int i = 0; i<element-1; ++i)
        {
            temp = temp.get()->next_node;
        }
        newElement.get()->next_node = temp.get()->next_node;
        temp.get()->next_node = newElement;

         if(list_size == UINT_MAX-1)
        {
            throw std::out_of_range("");
        }
        else
        {
            MyList::list_size = MyList::list_size+1;
        }

        return utils::RESULT_CODE::OK;
    }

}

template<typename T>
const utils::RESULT_CODE MyList<T>::printAll() const
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
const utils::RESULT_CODE MyList<T>::clear_list()
{
    MyList::head = nullptr;
    MyList::tail = nullptr;
    MyList::list_size = 0;
    return utils::RESULT_CODE::OK;
}

template<typename T>
const std::shared_ptr<Node<T>> MyList<T>::getElement(const unsigned int & element) const
{
    if (element >= MyList::getSize())
    {
        throw std::out_of_range("");
    }
    std::shared_ptr<Node<T>> temp = MyList::head;
    if( MyList::head == nullptr )
    {
        throw std::invalid_argument("");
    }
    for( unsigned int i = 0; i < element; ++i)
    {
        if( temp == nullptr )
        {
            throw std::invalid_argument("");
        }
        temp = temp.get()->next_node;
    }
    return temp;

}

template<typename T>
const bool MyList<T>::isEmpty() const
{
    if (MyList<T>::list_size == 0)
    {
        return true;
    }
    return false;
}
