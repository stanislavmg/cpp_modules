#include "Harl.h"

int main(int ac, char **av)
{
	Harl		test;
	
	if (ac > 1)
		test.complain(av[1]);
	return (0);
}
