#include "Harl.h"


int main(void)
{
	std::string input;
	Harl		test;

	while (1){
		std::cout << "Available option:\n1.DEBUG\n2.INFO\n3.WARNING\n4.ERROR\n5.EXIT\n\n";
		std::getline(std::cin, input);
		if (input == "EXIT")
			return (0);
		test.complain(input);
	}
	return (0);
}
