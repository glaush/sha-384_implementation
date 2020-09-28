#pragma once
#include <string>

template <typename T = std::string>
class Message
{
public:
    static T get_message();
    static T set_message(const char*);
    static T set_message(T mess);

private:
    inline static T digest = "";
};


template<typename T>
inline T Message<T>::get_message()
{
    return digest;
}

template<typename T>
inline T Message<T>::set_message(const char* mess)
{
    digest = mess;
    return digest;
}

template<typename T>
inline T Message<T>::set_message(T mess)
{
    digest = mess;
    return digest;
}
