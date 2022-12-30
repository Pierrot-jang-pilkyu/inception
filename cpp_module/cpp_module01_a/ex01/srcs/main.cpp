#include "../includes/Zombie.hpp"

int	main(void)
{
	Zombie	*horde;

	horde = zombieHorde(5, "Lodwig");
	for (int i = 0; i < 5; i++)
		horde[i].announce();
	delete[] horde;
	horde = NULL;
	return (0);
}
