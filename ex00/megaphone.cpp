#include <iostream>

class Megaphone
{

public:

	void shout(int argc, const char **message);
	
private:

	std::string _message;
	
	void _catArgv(const char **argv);
	void _messageToUpper(const std::string& message) const;
};

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

int main(int argc, char **argv)
{
	Megaphone mega;

	mega.shout(argc, (const char**)argv);
	mega.shout(argc, (const char**)argv);

	return 0;
}