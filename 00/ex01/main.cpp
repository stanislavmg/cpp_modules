#include "PhoneBook.h"

int	main(void)
{
	PhoneBook	pb;
	std::string	input;

	while (1)
	{
		std::cout << "Enter phone book operation:" << std::endl;
		std::cout << "1. ADD" << std::endl;
		std::cout << "2. SEARCH" << std::endl;
		std::cout << "3. EXIT" << std::endl;
		std::getline(std::cin, input);
		if(input == "1")
			pb.add();
		else if (input == "2")
			pb.search();
		else if (input == "3")
			break ;
		else
			std::cout << "Incorrect option. Try again." << std::endl;
	}
	return (0);
}

