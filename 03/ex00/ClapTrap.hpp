#pragma once
#include <iostream>
#include <string>

class ClapTrap
{
public:
    ClapTrap();
    ClapTrap(const std::string& val);
    ~ClapTrap();
    ClapTrap(const ClapTrap& val);
    ClapTrap& operator=(const ClapTrap& val);
    void attack(const std::string& target);
    void takeDamage(unsigned amount);
    void beRepaired(unsigned amount);
private:
    std::string name;
    int hit_points;
    int attack_damage;
    int energy_points;
};