#include "../includes/Weapon.hpp"

Weapon::Weapon() : type(NULL) {}

Weapon::Weapon(std::string type) : type(type) {}

Weapon::~Weapon() {}

std::string	Weapon::getType(void)
{
	return (this->type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}
