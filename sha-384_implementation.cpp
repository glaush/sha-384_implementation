#include <iostream>
#include "SHA384.h"

int main()
{
    Message<std::string>::set_message("abc");

    SHA384<std::string> obj(Message<std::string>::get_message());


    return 0;
}
