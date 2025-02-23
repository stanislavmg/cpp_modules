#include "ClapTrap.hpp"

int main() {
  ClapTrap Kenpachi("Kenpachi Zaraki");
  ClapTrap Unohana("Retsu Unohana");

  Kenpachi.attack("Retsu Unohana");
  Unohana.takeDamage(7);
  Unohana.beRepaired(1);
  return (0);
}