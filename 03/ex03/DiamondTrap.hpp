#pragma once
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap
    : public ScavTrap, public FragTrap
{
public:
    DiamondTrap();
    DiamondTrap(const std::string &val);
    virtual ~DiamondTrap();
    DiamondTrap(const DiamondTrap &val);
    DiamondTrap &operator=(const DiamondTrap &val);
    void whoAmI();
private:
    std::string name;
};