#include "ClapTrap.hpp"
#include <climits>

ClapTrap::ClapTrap() : hit_points(10), attack_damage(0), energy_points(10) {
  std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &val)
    : name(val), hit_points(10), attack_damage(0), energy_points(10) {
  (void)val;
  std::cout << "ClapTrap main constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &val) {
  std::cout << "ClapTrap copy constructor called" << std::endl;
  *this = val;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &val) {
  std::cout << "ClapTrap copy assignment operator called" << std::endl;
  if (this != &val) {
    name = val.name;
    hit_points = val.hit_points;
    attack_damage = val.attack_damage;
    energy_points = val.energy_points;
  }
  return *this;
}

void ClapTrap::attack(const std::string &target) {
  if (energy_points) {
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
              << attack_damage << " points of damage!" << std::endl;
    energy_points--;
  } else {
    std::cout << "ClapTrap " << name << " is out of energy!" << std::endl;
    return;
  }
}

void ClapTrap::takeDamage(unsigned amount) {
  std::cout << "ClapTrap " << name << " takes " << amount
            << " points of damage!" << std::endl;
  if (hit_points - amount > 0) {
    hit_points -= amount;
  } else {
    std::cout << "ClapTrap " << name << " is dead!" << std::endl;
    hit_points = 0;
  }
}

void ClapTrap::beRepaired(unsigned amount) {
  if (!energy_points) {
    std::cout << "ClapTrap " << name << " is out of energy!" << std::endl;
    return;
  }
  if (hit_points + amount < UINT_MAX) {
    std::cout << "ClapTrap " << name << " is repaired for " << amount
              << " points!" << std::endl;
    hit_points += amount;
  } else {
    std::cout << "ClapTrap " << name << " is fully repaired!" << std::endl;
    hit_points = UINT_MAX;
  }
}
