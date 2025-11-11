#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <limits>

int	main(void)
{
	PhoneBook book;
	std::string input_user;

	do { // NOLINT
		std::cout << "Enter one of the three commands: ADD, SEARCH or EXIT" << std::endl; // NOLINT (ensure correct display order)
		if (!std::getline(std::cin, input_user))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Error reading input, try again.\n";
			return 1;
		}
		if (input_user == "ADD")
		{
			if (!book.addContact())
			{
				return 1;
			}
		}
		else if (input_user == "SEARCH")
		{
			if (!book.displayContacts())
			{
				return 1;
			}
		}
	} while (input_user != "EXIT");

	return 0;
}
