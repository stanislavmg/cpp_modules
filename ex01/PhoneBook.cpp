#include "PhoneBook.h"

void	PhoneBook::add(void)
{
	if (index + 1 == max)
		list[index].clear();
	list[index].init();
	if (index + 1 < max)
		index++;
}

void	PhoneBook::search(void)
{
	int		input;
	char	ch;
	
	std::cout << "Enter index from 0 to 7: " << std::endl;
	std::cin >> input;
	
	while (std::cin.get(ch) && ch != '\n');
	if (input >= 0 && input < max)
		list[input].display(input);
	else
		std::cout << "Incorrect index" << std::endl;
}

