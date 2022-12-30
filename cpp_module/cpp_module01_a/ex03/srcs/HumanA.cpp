#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon &_weapon) : weapon(_weapon), name(_name) {}

HumanA::~HumanA() {}

void	HumanA::attack(void) const
{
	std::cout << this->name << "  attacks with their " << this->weapon.getType() << std::endl;
}
