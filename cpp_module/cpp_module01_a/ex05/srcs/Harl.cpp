#include "../includes/Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	void		(Harl::*fp[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string	lv[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	int	idx =	(int)(lv[0] == level & 1) * 1 + \
				(int)(lv[1] == level & 1) * 2 + \
				(int)(lv[2] == level & 1) * 3 + \
				(int)(lv[3] == level & 1) * 4;
	
	if (idx == 0)
		return ;
	(this->*fp[idx - 1])();
}
