#include "ScavTrap.hpp"

int main() {
  ScavTrap scav("TestBot");

  scav.attack("Target1");

  scav.takeDamage(20);

  scav.beRepaired(10);

  scav.guardGate();

  return 0;
}