#include "../includes/Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	temp(name);

	temp.announce();
}
