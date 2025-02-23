#pragma once
#include <iostream>
#include <string>

class ClapTrap
{
public:
    ClapTrap();
    ClapTrap(const std::string& val);
    virtual ~ClapTrap();
    ClapTrap(const ClapTrap& val);
    ClapTrap& operator=(const ClapTrap& val);
    virtual void attack(const std::string& target);
    virtual void takeDamage(unsigned amount);
    virtual void beRepaired(unsigned amount);
protected:
    std::string name;
    int hit_points;
    int attack_damage;
    int energy_points;
};