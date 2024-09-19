#include "Zombie.h"

int main(void)
{
	Zombie *nz = newZombie("ZZZZombie");
	randomChump("brain");
	delete nz;
	return (0);
}

