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
	int i;
	const char *arr[size] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (i = 0; i < size; i++){
		if (level == arr[i]){
			(this->*lvl[i])();
			return ;
		}
	}
	if (i == size)
		std::cout << "Incorrect option. Please try again" << std::endl;
}

