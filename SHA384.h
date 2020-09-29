#pragma once
#include <string>
#include <bitset>
#include <sstream>
#include <iomanip>
#include "SHA384Utils.h"
//#include <ranges>

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
inline T SHA384<T>::preprocessing(T mess)
{
    std::stringstream ss;
    uint64_t l{ 8 * (uint64_t)mess.length() };
    uint64_t k{ (896 - (1 + l)) % 1024 };
    std::bitset<128>bits_view_of_mess_length(l);

    for (size_t i = 0; i < mess.length(); i++)
    {
        std::bitset<8> bitsView(mess[i]);
        ss << bitsView.to_string();
    }
    ss << '1';
    ss << std::setfill('0');
    ss << std::setw(k + 128) << bits_view_of_mess_length;
        return ss.str();
}

template <typename T>
inline T SHA384<T>::hashComputation(T)
{
    return T();
}
