#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#define ATTACK " attacks with their "

class Weapon
{
	std::string _type;
public:
	Weapon(): _type() {}
	//Weapon(const Weapon &w): _type(w.getType()) {}
	Weapon(std::string type) {_type = type;}
	const std::string &getType(void) const {return (_type);}
	void setType(std::string type) {_type = type;}
};

#endif

