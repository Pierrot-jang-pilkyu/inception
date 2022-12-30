#include "../includes/Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl		harl;

	if (argc != 2)
		return (harl.filter("argument error"));
	return (harl.filter(argv[1]));
}
