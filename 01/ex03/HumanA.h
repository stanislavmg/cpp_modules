#ifndef HUMAN_A_H
#define HUMAN_A_H

#include "Weapon.h"
#include <iostream>

class HumanA
{
	std::string	_name;
	Weapon		&_weapon;
public:
	HumanA(std::string name, Weapon &weapon): _weapon(weapon) {_name = name;}
	void attack(void) {std::cout << _name << ATTACK << _weapon.getType() << std::endl; }
	void setWeapon(Weapon &weapon) {_weapon = weapon;}
};


#endif
