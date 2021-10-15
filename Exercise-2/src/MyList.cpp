#include "MyList.hpp"

template <typename T>
MyList<T>::MyList() : list_size(0), m_head(nullptr), tail(nullptr)
{
    //ctor
}

template<typename T>
MyList<T>::~MyList()
{
    //clear_list();
}

template <typename T>
const size_t MyList<T>::getSize() const
{
    return MyList<T>::list_size;
}

template<typename T>
const utils::RESULT_CODE MyList<T>::back_push(const T & object)
{
    auto newElement = std::make_shared<Node<T>>();
    newElement.get()->next_node = nullptr;
    newElement.get()->value = std::move(object);

    if (MyList::m_head == nullptr)
    {
        MyList::m_head = newElement;
        tail = newElement;
    }
    MyList::tail.get()->next_node = newElement;
    MyList::tail = newElement;

    if(list_size == UINT_MAX-1)
    {
        return utils::RESULT_CODE::OUT_OF_BOUND;
    }
    else
    {
      ++MyList::list_size;
    }

    return utils::RESULT_CODE::OK;
}

template<typename T>
const utils::RESULT_CODE MyList<T>::front_push(const T& object)
{
    if( MyList::isEmpty() == true )
    {
        return MyList::back_push(object);
    }
    auto newElement = std::make_shared<Node<T>>();
    newElement.get()->next_node = MyList::m_head;
    newElement.get()->value = object;

    MyList::m_head = newElement;

    if(list_size == UINT_MAX-1)
    {
        return utils::RESULT_CODE::OUT_OF_BOUND;
    }
    else
    {
      ++MyList::list_size;
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

    std::shared_ptr<Node<T>> ptrOnElem = MyList::m_head;
    std::cout << std::endl << std::endl;
    std::cout << "head: " << m_head.get() << std::endl;
    for( unsigned int i = 0; i < MyList::getSize()-1; ++i) //make it on while ptrOnElem != nullptr
    {
        ptrOnElem = ptrOnElem.get()->next_node;
        std::cout << i << ": " << ptrOnElem << std::endl;
        if( ptrOnElem == nullptr )
        {
            return utils::RESULT_CODE::NULLPTR_CALLED;
        }
    }
    std::cout << std::endl;
    auto temp = m_head.get()->next_node; //drugi element
    delete m_head.get();
    m_head = std::move(nullptr);
    if (temp != nullptr)
    {
        m_head = std::move(temp);

    }
    --MyList::list_size;

    return utils::RESULT_CODE::OK;
}

template<typename T>
const utils::RESULT_CODE MyList<T>::back_pop()
{
    if (MyList::isEmpty() == true)
    {
        return utils::RESULT_CODE::OUT_OF_BOUND;
    }

    if( MyList::m_head == nullptr )
    {
        return utils::RESULT_CODE::NULLPTR_CALLED;
    }

    std::shared_ptr<Node<T>> ptrOnElem = MyList::m_head;
    for( unsigned int i = 0; i < MyList::getSize()-1; ++i) //make it on while ptrOnElem != nullptr
    {
        ptrOnElem = ptrOnElem.get()->next_node;
        if( ptrOnElem == nullptr )
        {
            return utils::RESULT_CODE::NULLPTR_CALLED;
        }
    }
    tail = std::move(ptrOnElem);
    delete ptrOnElem.get();


    --MyList::list_size;
    return utils::RESULT_CODE::OK;
}

template<typename T>
const utils::RESULT_CODE MyList<T>::insert_to_list(unsigned int element, const T & object) //change on std::size_t element
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

        std::shared_ptr<Node<T>> temp = m_head;
        for(unsigned int i = 0; i<element-1; ++i)
        {
            temp = temp.get()->next_node;
        }
        newElement.get()->next_node = std::move(temp.get()->next_node);
        temp.get()->next_node = newElement;
        if(list_size == UINT_MAX-1)
        {
            throw std::out_of_range("");
        }
        else
        {
            ++MyList::list_size;
        }

        return utils::RESULT_CODE::OK;
    }

}

template<typename T>
const utils::RESULT_CODE MyList<T>::printAll() const
{
    auto temp = MyList::m_head;
    if (temp == nullptr)
    {
        return utils::RESULT_CODE::NULLPTR_CALLED;
    }
    for( std::size_t i = 0; i < list_size; ++i )
    {
        if( temp == nullptr )
        {
            return utils::RESULT_CODE::NULLPTR_CALLED;
        }
        std::cout<<temp.get()->value << ",";
        temp = temp.get()->next_node;
    }
    return utils::RESULT_CODE::OK;
}

template<typename T>
const utils::RESULT_CODE MyList<T>::clear_list()
{
    auto temp = MyList::m_head;
    auto tempSize = list_size;
    for(std::size_t i = 0; i<tempSize;++i)
    {
        back_pop();
    }
    return utils::RESULT_CODE::OK;
}

template<typename T>
const std::shared_ptr<Node<T>> MyList<T>::getElement(const unsigned int & element) const
{
    if (element >= MyList::getSize())
    {
        throw std::out_of_range("");
    }
    std::shared_ptr<Node<T>> temp = MyList::m_head;
    if( MyList::m_head == nullptr )
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
