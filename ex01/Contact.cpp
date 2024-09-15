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
	~Contact() {};
};

Contact::Contact()
{

}
