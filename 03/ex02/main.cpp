#include "FragTrap.hpp"

int main() {
  FragTrap frag("TestBot");

  frag.attack("Target1");

  frag.takeDamage(20);

  frag.beRepaired(10);

  frag.highFivesGuys();

  return 0;
}