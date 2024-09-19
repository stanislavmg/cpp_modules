#include "PhoneBook.h"

std::string	&Contact::resize(std::string &str)
{
	if (str.size() > 10)
	{
		str.resize(10);
		str.back() = '.';
	}
	return (str);
}

void	Contact::init()
{
	int i = 0;
	std::string	input;

	while (i < size) 
	{
		std::getline(std::cin, input);
		for (size_t j = 0; j < input.size(); ++j)
		{
			if (input[j] != ' ')
				data[i].push_back(input[j]);
		}
		if (!data[i].size())
		{
			std::cout << "Field shouldn't be emty\nPlease try again" << std::endl;
			continue;
		}
		resize(data[i]);
		i++;
	}
}

void	Contact::display(int index) const
{
	int i = -1;

	std::cout.setf(std::ios::right);
	std::cout << std::setw(8) << std::right << index << " | ";
	while (++i < size)
		std::cout << std::setw(8) << std::right << data[i] << " | ";
	std::cout << std::endl;
}

void	Contact::clear(void)
{
	for (size_t i = 0; i < size; ++i)
		data[i].clear();
}

