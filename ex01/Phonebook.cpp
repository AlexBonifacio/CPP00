#include "Phonebook.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <iomanip> //std::setw std::right

using	std::cout;
using	std::endl;
using	std::cin;


PhoneBook::PhoneBook() : _next(0), _curr(-1), _count(0), _full(false)
{}

bool	PhoneBook::addContact()
{
	_curr = _next;

	if (!_contacts[_curr].setFromInput()) // NOLINT (cppcoreguidelines-pro-bounds-constant-array-index,-warnings-as-errors)
	{
		return false;
	}

	_next++;
	if (!_full)
	{
		_count = _next;
	}
	else
	{
		_count = BOOK_SIZE;
	}

	if (_next == BOOK_SIZE)
	{
		_full = true;
		_next = 0;
	}
	return true;
}

bool	PhoneBook::displayContacts()
{
	int index = 0;

	_displayHeader();
	_displayTab();

	cout << "Enter contact index to display his contact: " << std::flush;
	if (!(cin >> index))
	{
		if (cin.eof())
		{
			return false;
		}
		_cinClear();
		cout << "Invalid input" << '\n';
		return true;

	}

	char next;
	if (std::cin.get(next) && next != '\n') 
	{
    	std::cout << "Invalid input (extra characters after number)\n";
    	_clearCinBuffer();
    	return true;
	}
	
	if (index >= BOOK_SIZE || index < 0 || index > _curr)
	{
		cout << "Invalid index" << '\n';
		return true;
	}
	cout << "Displaying contact at index " << index << ":" << '\n';
	_contacts[index].displayContact(); // NOLINT (cppcoreguidelines-pro-bounds-constant-array-index,-warnings-as-errors)

	return true;
}

void	PhoneBook::_cinClear()
{
	cin.clear();
	_clearCinBuffer();
}

// clear input buffer in case input is Index+something (0ABC)
void	PhoneBook::_clearCinBuffer() 
{
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string PhoneBook::_formatTab(const std::string& str)
{
	if (str.length() > WIDTH)
	{
		return str.substr(0, (WIDTH - 1)) + ".";
	}
	return str;
}

void	PhoneBook::_displayHeader() // NOLINT (static)
{
	cout << "|----------|----------|----------|----------|\n";
	cout << "|" << std::setw(WIDTH) << std::right << "Index"
	          << "|" << std::setw(WIDTH) << std::right << "First Name"
	          << "|" << std::setw(WIDTH) << std::right << "Last Name"
	          << "|" << std::setw(WIDTH) << std::right << "Nickname" << "|" << '\n';
	cout << "|----------|----------|----------|----------|\n";
}

void	PhoneBook::_displayTab()
{
	for (std::size_t i = 0; i < _count; i++)
	{
		std::string firstName = _formatTab(_contacts[i].getFirstName()); // NOLINT (cppcoreguidelines-pro-bounds-constant-array-index,-warnings-as-errors)
		std::string lastName = _formatTab(_contacts[i].getLastName()); // NOLINT
		std::string nickName = _formatTab(_contacts[i].getNickName()); // NOLINT

		cout << "|" << std::setw(WIDTH) << std::right << i
		          << "|" << std::setw(WIDTH) << std::right << firstName
		          << "|" << std::setw(WIDTH) << std::right << lastName
		          << "|" << std::setw(WIDTH) << std::right << nickName
		          << "|" << '\n';
	}
	cout << "|----------|----------|----------|----------|\n";
}
