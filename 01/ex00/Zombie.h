#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie
{
	std::string	_name;
public:
	Zombie( std::string name );
	~Zombie();
	void	announce( void ) { std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;}
};

Zombie	*newZombie( std::string name );
void randomChump( std::string name );

#endif
