#include "Zombie.h"

int main(void)
{
	int N = 10;
	Zombie *nz = newZombie("ZZZZombie");
	Zombie *arr = zombieHorde(N, "Max");
	randomChump("brain");
	for (int i = 0; i < N; ++i){
		arr[i].announce();
	}
	delete nz;
	delete [] arr;
	return (0);
}

