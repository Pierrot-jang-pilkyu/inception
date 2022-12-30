#include "../includes/Zombie.hpp"

int	main(void)
{
	Zombie	bob("Bob");
	Zombie	pop;
	Zombie	*nzom;

	bob.announce();
	pop.setZombieName("Pop");
	pop.announce();
	randomChump("Foo");
	nzom = newZombie("John");
	nzom->announce();
	delete[] nzom;
	nzom = NULL;
	return (0);
}
