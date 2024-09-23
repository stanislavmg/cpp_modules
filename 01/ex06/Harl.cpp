#include "Harl.h"

Harl::Harl()
{
	lvl[0] = &Harl::debug;
	lvl[1] = &Harl::info;
	lvl[2] = &Harl::warning;
	lvl[3] = &Harl::error;
}

void	Harl::debug(void)
{
	std::cout << "DEBUG message" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "INFO message" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING message" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "ERROR message" << std::endl;
}

void	Harl::complain(std::string level)
{
	int i = 0;
	const char *arr[size] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	while (i < size && level != arr[i])
		i++;
	if (i == size){
		std::cout << "Incorrect option. Please try again" << std::endl;
		return ;
	}
	for (int j = i; j < size; j++)
			(this->*lvl[j])();
}
