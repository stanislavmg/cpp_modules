#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {
public:
  ScavTrap();
  ScavTrap(const std::string &val);
  virtual ~ScavTrap();
  ScavTrap(const ScavTrap &val);
  ScavTrap &operator=(const ScavTrap &val);
  void attack(const std::string &target);
  void takeDamage(unsigned amount);
  void beRepaired(unsigned amount);
  void guardGate();
};