#include "Contact.hpp"
#include <iostream>
#include <limits>

using	std::cout;
using	std::endl;

Contact::Contact(){}

bool Contact::setFromInput()
{
	
	do {
		std::cout << "First name: " << std::endl; // NOLINT (ensure correct display order)
		if (!std::getline(std::cin, _firstName))
		{
			return _cleandupInput();
		}
	} while (_firstName.empty());

	do {
	cout << "Last name: " << std::endl; // NOLINT (ensure correct display order)
	if (!std::getline(std::cin, _lastName))
	{
		return _cleandupInput();
	}
	} while (_lastName.empty());

	do {
	cout << "Nickname: " << std::endl; // NOLINT (ensure correct display order)
	if (!std::getline(std::cin, _nickName))
	{
		return _cleandupInput();
	}
	} while (_nickName.empty());
	
	do {
		cout << "Phone number: " << std::endl; // NOLINT (ensure correct display order)
		if (!std::getline(std::cin, _phoneNumber))
		{
			return _cleandupInput();
		}
	} while (_phoneNumber.empty());

	do {
		cout << "Darkest secret: " << std::endl; // NOLINT (ensure correct display order)
		if (!std::getline(std::cin, _darkestSecret))
		{
			return _cleandupInput();
		}
	} while (_darkestSecret.empty());
	return true;
}


const std::string& Contact::getFirstName() const
{
	return _firstName;
}

const std::string& Contact::getLastName() const
{
	return _lastName;
}

const std::string& Contact::getNickName() const
{
	return _nickName;
}

void	Contact::displayContact() const
{
	cout << _firstName << '\n';
	cout << _lastName << '\n';
	cout << _nickName << '\n';
	cout << _phoneNumber << '\n';
	cout << _darkestSecret << '\n';
}

bool	Contact::_cleandupInput()
{
	if (std::cin.eof()) 
	{
		return false;
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return true;
}
