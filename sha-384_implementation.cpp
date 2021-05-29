#include <iostream>
#include <fstream>
#include "SHA384.h"

int main()
{
    try
    {
        Message<std::string>::set_message("abc");

        SHA384<std::string> sha_obj(Message<std::string>::get_message());
        
        std::cout << "Output digest: ";
        std::cout << Message<std::string>::get_digest() << std::endl;
        return 0;
    }
    catch (const std::exception& e)
    {
    			 std::cout <<	e.what() << std::endl;
        return -1;
    }
}
