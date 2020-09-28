#pragma once
#include <string>
#include "SHA384Utils.h"

template <typename T = std::string>
class SHA384
{
public:
    SHA384(T&&);

    T preprocessing(T);
    T hashComputation(T);
private:

};

template <typename T>
inline SHA384<T>::SHA384(T&& pmess)
{
    Message<std::string>::set_message(preprocessing(pmess));
    hashComputation(Message<std::string>::get_message());
   
    /* :
    hashComputation(Message<std::string>::get_message()),Message<std::string>::set_message(preprocessing(obj))*/
}

template <typename T>
inline T SHA384<T>::preprocessing(T pmess)
{
    return std::string();
}

template <typename T>
inline T SHA384<T>::hashComputation(T)
{
    return T();
}
