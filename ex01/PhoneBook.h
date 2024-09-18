#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

class Contact
{
	static const int size = 5;
	std::string	 data[size];
	std::string	&resize(std::string &str);
public:
	void	display(int index) const;
	void	init(void);
	void	clear(void);
};


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

#endif
