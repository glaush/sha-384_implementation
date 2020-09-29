#include <iostream>
#include "SHA384.h"

int main()
{
				try
				{
				std::cout << "Enter the message: ";

				std::string message;

				getline(std::cin,message,'\n');

				/*Message<std::string>::set_message("abc");*/

				Message<std::string>::set_message(message);

				SHA384<std::string> sha_obj(Message<std::string>::get_message());

				std::cout << "Output digest: ";

				std::cout << Message<std::string>::get_digest() << std::endl;

				}
				catch (const std::exception& e)
				{
							std::cout <<	e.what() << std::endl;
				}
				
				return 0;
}
