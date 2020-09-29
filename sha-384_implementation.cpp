#include <iostream>
#include <fstream>
#include "SHA384.h"

int main()
{
				try
				{
				std::cout << "Read message from file or stream? (f/s)\n";
		
				std::string message;
				char your_choice;

				std::cin >> your_choice;

				if (your_choice == 'f')
				{
								std::cout << "Please, enter the path to file: ";
								std::string path_to_file;
								std::cin >> path_to_file;
								std::ifstream file(path_to_file);
								
								if (file.is_open())
								{
												file >> message;
								}
								else
												throw std::runtime_error("Error with file!\n");
				}
				else
				{
								std::cout << "Enter the message: ";

								std::cin.ignore(std::cin.rdbuf()->in_avail());
								std::cin.clear();
								getline(std::cin, message, '\n');

								/*Message<std::string>::set_message("abc");*/
				}

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
