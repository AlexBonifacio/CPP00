#include "megaphone.hpp"
#include <cstring>

Megaphone::Megaphone() {}
Megaphone::~Megaphone() {}

void Megaphone::shout(int argc, const char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		_catArgv(argv);
		_messageToUpper(this->_message);
	}
}

void Megaphone::_catArgv(const char **argv)
{
	_message.clear();

	for (int i = 1; argv[i]; i++)
	{
		this->_message += argv[i];
		if (argv[i + 1] != NULL)
			this->_message += " ";
	}
}

void Megaphone::_messageToUpper(const std::string& message) const
{
	char c;

	for (int i = 0; message[i]; i++)
	{
		c = toupper(message[i]);
		std::cout << c;
	}
	std::cout << std::endl;
}