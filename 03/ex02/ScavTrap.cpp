#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
  std::cout << "ScavTrap default constructor called" << std::endl;
  hit_points = 100;
  attack_damage = 20;
  energy_points = 50;
}

ScavTrap::ScavTrap(const std::string &val): ClapTrap(val) {
  std::cout << "ScavTrap main constructor called" << std::endl;
  hit_points = 100;
  attack_damage = 20;
  energy_points = 50;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &val) {
  std::cout << "ScavTrap copy constructor called" << std::endl;
  *this = val;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &val) {
  std::cout << "ScavTrap copy assignment operator called" << std::endl;
  if (this != &val) {
    name = val.name;
    hit_points = val.hit_points;
    attack_damage = val.attack_damage;
    energy_points = val.energy_points;
  }
  return *this;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " has entered in Gate keeper mode"
                << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    if (energy_points) {
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing "
                << attack_damage << " points of damage!" << std::endl;
        energy_points--;
    } else {
        std::cout << "ScavTrap " << name << " is out of energy!" << std::endl;
        return;
    }
}

void ScavTrap::takeDamage(unsigned amount) {
    std::cout << "ScavTrap " << name << " takes " << amount
                << " points of damage!" << std::endl;
    if (hit_points - amount > 0) {
        hit_points -= amount;
    } else {
        std::cout << "ScavTrap " << name << " is dead!" << std::endl;
        hit_points = 0;
    }
}

void ScavTrap::beRepaired(unsigned amount) {
    if (!energy_points) {
        std::cout << "ScavTrap " << name << " is out of energy!" << std::endl;
        return;
    }
    if (hit_points + amount < UINT_MAX) {
        std::cout << "ScavTrap " << name << " is repaired for " << amount
                    << " points!" << std::endl;
    } else {
        std::cout << "ScavTrap " << name << " is fully repaired!" << std::endl;
        hit_points = UINT_MAX;
    }
}
