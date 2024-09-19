#include "Zombie.h"

Zombie::Zombie( std::string name )
{
	_name = name;
}

Zombie::~Zombie()
{
	std::cout << _name << std::endl;
}

Zombie	*newZombie( std::string name )
{
	Zombie *nz = new Zombie(name);
	return (nz);
}

void randomChump( std::string name )
{
	Zombie nz(name);
	
	nz.announce();
}

