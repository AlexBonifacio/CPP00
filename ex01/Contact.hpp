#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	public:
		Contact();
		
		bool				setFromInput();
		const std::string&	getFirstName() const;
		const std::string&	getLastName() const;
		const std::string&	getNickName() const;
		void				displayContact() const;
		
	private:
		std::string	_firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string	_darkestSecret;
		static bool	_cleandupInput();

};

#endif
