#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact		contact[8];
	int			addCount;

public:
	PhoneBook();
	int		getContactSize(void);
	void	openPhoneBook(PhoneBook &phoneBook);
	void	addPhoneBook(PhoneBook &phoneBook);
	void	searchPhoneBook(PhoneBook &phoneBook);
	void	printTenChar(std::string str);
	~PhoneBook();
};

#endif