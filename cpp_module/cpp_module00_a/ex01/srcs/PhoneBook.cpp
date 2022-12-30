#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->addCount = -1;
}

int		PhoneBook::getContactSize(void)
{
	return (this->addCount < 8 ? (this->addCount + 1) : 8);
}

void	PhoneBook::openPhoneBook(PhoneBook &phoneBook)
{
	std::string	cmd;

	while (1)
	{
		std::cout << std::endl << "Wellcome to phonebook." << std::endl;
		std::cout << "Please enter the command [ ADD / SEARCH / EXIT ]: ";
		std::getline(std::cin, cmd);
		if (cmd.compare("ADD") == 0)
			addPhoneBook(phoneBook);
		else if (cmd.compare("SEARCH") == 0)
			searchPhoneBook(phoneBook);
		else if (cmd.compare("EXIT") == 0)
		{
			std::cout << std::endl << "Thank you for using. Good luck." << std::endl;
			break ;
		}
		else
			std::cout << std::endl << "Error : Wrong command. Please must use uppercase character." << std::endl << std::endl;
	}
}

void	PhoneBook::addPhoneBook(PhoneBook &phoneBook)
{
	int		idx;
	std::string	str[5];

	phoneBook.addCount++;
	std::cout << std::endl << std::endl;
	std::cout << "1. Please enter the first name		: "; std::getline(std::cin, str[0]);
	std::cout << "2. Please enter the last name		: "; std::getline(std::cin, str[1]);
	std::cout << "3. Please enter the nick name		: "; std::getline(std::cin, str[2]);
	std::cout << "4. Please enter the phone number	: "; std::getline(std::cin, str[3]);
	std::cout << "5. Please enter the darkest secret	: "; std::getline(std::cin, str[4]);
	std::cout << std::endl << std::endl;
	
	idx = phoneBook.addCount % 8;
	phoneBook.contact[idx].setFirstName(str[0]);
	phoneBook.contact[idx].setLastName(str[1]);
	phoneBook.contact[idx].setNickName(str[2]);
	phoneBook.contact[idx].setPhoneNumber(str[3]);
	phoneBook.contact[idx].setDarkestSecret(str[4]);

	std::cout << "Your contact has been successfully saved." << std::endl;
	std::cout << std::endl << std::endl;
}

void	PhoneBook::searchPhoneBook(PhoneBook &phoneBook)
{
	int		idx;
	std::string	str;

	idx = -1;
	std::cout << "|------------------Contact------------------|" << std::endl;
	std::cout << "|     index|First Name| Last Name| Nick Name|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;

	while (++idx < phoneBook.getContactSize())
	{
		std::cout << "|" << std::setw(10) << idx;
		phoneBook.printTenChar(phoneBook.contact[idx].getFirstName());
		phoneBook.printTenChar(phoneBook.contact[idx].getLastName());
		phoneBook.printTenChar(phoneBook.contact[idx].getNickName());
		std::cout << "|" << std::endl;
	}

	std::cout << "|-------------------------------------------|" << std::endl << std::endl;

	if (phoneBook.getContactSize() == 0)
		return ;
	while (1)
	{
		std::cout << "Please enter the index of the contact you want to see [0 ~ 7] : "; std::getline(std::cin, str);
		if (std::stoi(str) > 7)
			std::cout << "Wrong Input data. " << std::endl << std::endl;
		else
		{
			idx = std::stoi(str);
			if (idx > phoneBook.getContactSize() - 1)
			{
				std::cout << "Can't search to the index in Phonebook." << std::endl;
				break ;
			}
			phoneBook.contact[idx].viewContact();
			break ;
		}
	}

}

void	PhoneBook::printTenChar(std::string str)
{
	if (str.size() <= 10)
		std::cout << "|" << std::setw(10) << str;
	else
		std::cout << "|" << std::setw(10) << str.substr(0, 9) << ".";
}

PhoneBook::~PhoneBook()
{
}