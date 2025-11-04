#include "Contact.hpp"
#include <iostream>
#include <limits>

using	std::cout;
using	std::endl;

Contact::Contact(){}

bool Contact::setFromInput()
{
	std::cout << "First name: " << std::endl; // NOLINT (ensure correct display order)
	if (!(std::cin >> _firstName)) 
	{
		return _cleandupInput();
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "Last name: " << std::endl; // NOLINT (ensure correct display order)
	if (!(std::cin >> _lastName)) 
	{
		return _cleandupInput();
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "Nickname: " << std::endl; // NOLINT (ensure correct display order)
	if (!(std::cin >> _nickName)) 
	{
		return _cleandupInput();
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "Phone number: " << std::endl; // NOLINT (ensure correct display order)
	if (!(std::cin >> _phoneNumber)) 
	{
		return _cleandupInput();
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "Darkest secret: " << std::endl; // NOLINT (ensure correct display order)
	if (!(std::cin >> _darkestSecret)) 
	{
		return _cleandupInput();
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
	std::cin.clear(); // clear the error flag
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
	return true;
}