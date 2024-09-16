#include <array>
#include <iostream>
#include <string>

class Contact
{
	std::string	FirstName;
	std::string	LastName;
	std::string	NickName;
	std::string	PhoneNum;
	std::string	Secret;
public:
	Contact();
	Contact(std::string fname, std::string lname, std::string pnum, std::string secret);
	~Contact() {};
	int	operator==();
};

Contact::Contact(): FirstName(), LastName(), NickName(), PhoneNum(), Secret()
{
	std::cout << "Enter First name: " << std::endl;
	std::cin.getline(FirstName);
	std::cout << "Last name: " << std::endl;
	std::cin.getline(LastName);
	std::cout << "Nick name: " << std::endl;
	std::cin.getline(NickName);
	std::cout << "Phone number: " << std::endl;
	std::cin.getline(PhoneNum);
	std::cout << "Your secret: " << std::endl;
	std::cin.getline(Secret);
}

int	Contact::operator==(Contact &rhs)
{
	return
	(
		this.FirstName == rhs.FirstName && this.LastName == rhs.LastName
		this.NickName == rhs.NickName && this.
	)
}

class PhoneBook
{
	std::array<Contact &, 8> list;
public:
	PhoneBook(): list() {};
	~PhoneBook() {};
	void	add(Contact new_contact);
	void	search(Contact target);
};

void	PhoneBook::add(Contact &new_contact)
{
	list[list.size() - 1] = new_contact;
}

void	PhoneBook::search(Contact target)
{
	int size = list.size();
	int	i = -1;

	for (++i < size)
	{
		if (list[i] == target)
			list[i].display();
	}
}

int	main(void)
{
	PhoneBook	pb();
	std::string	input;

	while (1)
	{
		std::cout << "Enter phone book operation:" << std::endl;
		std::cout << "ADD for add new contact" << std::endl;
		sdt::cout << "EXIT for exit" << std::endl;
		std::cin.getline(input);
		if(input == "ADD")
			pb.add(Contact::Contact());
		else if (input == "EXIT")
			break ;
	}
	return (0);
}
