#ifndef HUMAN_B_H
#define HUMAN_B_H

#include "Weapon.h"
#include <iostream>

class HumanB
{
	std::string	_name;
	Weapon		*_weapon;
public:
	HumanB(std::string name): _name(name) {_weapon = NULL;}
	HumanB(std::string name, Weapon &weapon): _name(name) {_weapon = &weapon;}
	void attack(void) {std::cout << _name << ATTACK << _weapon->getType() << std::endl;}
	void setWeapon(Weapon &weapon) {_weapon = &weapon;}
};


#endif
