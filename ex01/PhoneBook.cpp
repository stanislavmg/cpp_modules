#include "Contact.h"

class PhoneBook
{
	int	count;
	std::array<Contact> list;
public:
	PhoneBook() {count = 0; list();};
	~PhoneBook() {};
	void	add(Contact new);
	void	search(Contact target);
};

void	PhoneBook::add(Contact new)
{

}

void	PhoneBook::search(Contact target)
{

}
