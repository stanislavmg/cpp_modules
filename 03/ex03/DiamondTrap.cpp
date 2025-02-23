#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
  std::cout << "DiamondTrap default constructor called" << std::endl;
  hit_points = FragTrap::hit_points;
  attack_damage = FragTrap::attack_damage;
  energy_points = ScavTrap::energy_points;
}

DiamondTrap::DiamondTrap(const std::string &val)
    : ClapTrap(val), name(val + "_clap_name") {
  std::cout << "DiamondTrap main constructor called" << std::endl;
  hit_points = FragTrap::hit_points;
  attack_damage = FragTrap::attack_damage;
  energy_points = ScavTrap::energy_points;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &val) {
  std::cout << "DiamondTrap copy constructor called" << std::endl;
  *this = val;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &val) {
  std::cout << "DiamondTrap copy assignment operator called" << std::endl;
  if (this != &val) {
    DiamondTrap::name = val.DiamondTrap::name;
    ClapTrap::name = val.ClapTrap::name;
    hit_points = val.hit_points;
    attack_damage = val.attack_damage;
    energy_points = val.energy_points;
  }
  return *this;
}

void DiamondTrap::whoAmI() {
  std::cout << "DiamondTrap name is " << DiamondTrap::name << " and ClapTrap name is "
            << ClapTrap::name << std::endl;
}
