#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <limits>

int	main(void)
{
	PhoneBook book;
	std::string input_user;

	do { // NOLINT
		std::cout << "Enter one of the three commands: ADD, SEARCH or EXIT" << std::endl; // NOLINT (ensure correct display order)
		std::cin >> input_user;
		if (input_user == "ADD")
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (!book.addContact())
			{
				return 1;
			}
		}
		else if (input_user == "SEARCH")
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (!book.displayContacts())
			{
				return 1;
			}
		}
	} while (input_user != "EXIT");

	return 0;
}