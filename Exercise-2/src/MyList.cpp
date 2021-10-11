#include "MyList.hpp"

template <typename T>
MyList<T>::MyList() : list_size(0)
{
    //ctor
}

template <typename T>
MyList<T>::~MyList()
{
    //dtor
}


template <class T>
unsigned int MyList<T>::getSize()
{
    return MyList<T>::list_size;
}

template<class T>
utils::RESULT_CODE MyList<T>::back_push(T object)
{
    return utils::RESULT_CODE::UNKNOWN_ERROR;
}

template<typename T>
utils::RESULT_CODE MyList<T>::front_push(T object)
{
    return utils::RESULT_CODE::UNKNOWN_ERROR;
}

template<class T>
utils::RESULT_CODE MyList<T>::front_pop()
{
    return utils::RESULT_CODE::UNKNOWN_ERROR;
}

template<class T>
utils::RESULT_CODE MyList<T>::back_pop()
{
    return utils::RESULT_CODE::UNKNOWN_ERROR;
}

template<class T>
utils::RESULT_CODE MyList<T>::insert_to_list(unsigned int ,T object)
{
    return utils::RESULT_CODE::UNKNOWN_ERROR;
}

template<class T>
utils::RESULT_CODE MyList<T>::printAll()
{
    return utils::RESULT_CODE::UNKNOWN_ERROR;
}

template<class T>
utils::RESULT_CODE MyList<T>::clear_list()
{
    return utils::RESULT_CODE::UNKNOWN_ERROR;
}

template<class T>
T MyList<T>::getElement(unsigned int element)
{
    return utils::RESULT_CODE::UNKNOWN_ERROR;
}

template<class T>
bool MyList<T>::isEmpty()
{
    return false;
}
