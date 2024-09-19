#include <iostream>
#include <string>
#include <cstdlib>

class Megaphone
{
	char	**str;
	public:
	Megaphone() { str = 0; };
	Megaphone(char **argv) { str = argv; };
	~Megaphone() {};
	void UpperCase(void);
	void Display(void);
};

void Megaphone::UpperCase(void)
{
	int	i = 1;

	while(str[i])
	{
		int	j = -1;
		while(str[i][++j])
			str[i][j] = std::toupper(str[i][j]);
		++i;
	}
}

void Megaphone::Display(void)
{
	int	i = 0;

	while(str[++i])
		std::cout << str[i];
	std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	Megaphone tmp(argv);
	tmp.UpperCase();
	tmp.Display();
	return (0);
}
