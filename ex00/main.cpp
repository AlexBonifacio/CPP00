#include "megaphone.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	Megaphone mega;

	mega.shout(argc, (const char**)argv);
	mega.shout(argc, (const char**)argv);

	return 0;
}