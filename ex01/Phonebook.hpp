#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#define BOOK_SIZE 8
#define WIDTH 10
#include "Contact.hpp"

class PhoneBook
{
	public:
	
		PhoneBook();
		
		bool	addContact();
		bool	displayContacts();
		
	private:
		
		static std::string	_formatTab(const std::string& str);
		static void			_cinClear();
		static void			_clearCinBuffer();

		
		Contact 	_contacts[BOOK_SIZE];
		std::size_t	_next;
		int			_curr;
		std::size_t _count;
		bool		_full;

		void		_displayHeader();
		void		_displayTab();

};

#endif
