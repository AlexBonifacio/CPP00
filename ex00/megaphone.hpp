#ifndef MEGAPHONE_HPP
#define MEGAPHONE_HPP

#include <iostream>

class Megaphone
{

public:
	Megaphone();
	~Megaphone();

	void shout(int argc, const char **message);
	
private:

	std::string _message;
	
	void _catArgv(const char **argv);
	void _messageToUpper(const std::string& message) const;
};

#endif 