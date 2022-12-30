#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name) : weapon(NULL), name(name) {}

HumanB::~HumanB() {}

void	HumanB::attack(void) const
{
	std::cout << this->name << "  attacks with their " << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &_weapon)
{
	this->weapon = &_weapon;
}
