#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>

class Zombie
{
private:
	std::string	name;
public:
	Zombie();
	Zombie(std::string name);
	void		announce(void);
	void		setZombieName(std::string name);
	std::string	getZombieName(void);
	~Zombie();
};

Zombie*	zombieHorde(int N, std::string name);

#endif
