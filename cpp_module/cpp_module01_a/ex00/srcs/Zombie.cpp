#include "../includes/Zombie.hpp"

Zombie::Zombie()
{
	this->name = "";
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setZombieName(std::string name)
{
	this->name = name;
}

std::string	Zombie::getZombieName(void)
{
	return (this->name);
}

Zombie::~Zombie()
{
	std::cout << this->name << " is dead." << std::endl;
}
