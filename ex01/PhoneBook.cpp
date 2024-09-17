#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
	static const int size = 5;
	std::string	 data[size];
	std::string	&resize(std::string &str);
public:
	void	display(int index) const;
	void	init(void);
};

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
		std::getline(std::cin, data[i]);
		data[i].erase(data[i].find(' '));
		//while (std::isspace(data[i].begin()))
				//data[i].
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

class PhoneBook
{
	static const int	max = 8;
	Contact 			list[max];
	int					index;
public:
	PhoneBook(){ index = 0; }
	void			add(void);
	void			search(void);
};

void	PhoneBook::add(void)
{
	list[index].init();
	if (index + 1 < max)
		index++;
}

void	PhoneBook::search(void)
{
	int		input;
	char	ch;
	
	std::cout << "Enter index less than 8: " << std::endl;
	std::cin >> input;
	
	while (std::cin.get(ch) && ch != '\n');
	if (input >= 0 && input < max)
		list[input].display(input);
	else
		std::cout << "Incorrect index" << std::endl;
}

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
