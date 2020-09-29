#pragma once
#include <string>

template <typename T = std::string>
class Message
{
public:
    static T get_message();
    static T set_message(const char*);
    static T set_message(T mess);

    static T set_digest(T mess);
    static T get_digest(T mess);

private:
    inline static T message = "";
    inline static T digest = "";
};


template<typename T>
inline T Message<T>::get_message()
{
    return message;
}

template<typename T>
inline T Message<T>::set_message(const char* mess)
{
    message = mess;
    return message;
}

template<typename T>
inline T Message<T>::set_message(T mess)
{
    digest = mess;
    return digest;
}

template<typename T>
inline T Message<T>::set_digest(T mess)
{
    return T();
}

template<typename T>
inline T Message<T>::get_digest(T mess)
{
    return T();
}
