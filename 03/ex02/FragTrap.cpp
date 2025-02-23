#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() {
    std::cout << "FragTrap default constructor called" << std::endl;
    hit_points = 100;
    attack_damage = 30;
    energy_points = 100;
}

FragTrap::FragTrap(const std::string &val) : ClapTrap(val) {
    std::cout << "FragTrap main constructor called" << std::endl;
    hit_points = 100;
    attack_damage = 30;
    energy_points = 100;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &val) {
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = val;
}

FragTrap &FragTrap::operator=(const FragTrap &val) {
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &val) {
        name = val.name;
        hit_points = val.hit_points;
        attack_damage = val.attack_damage;
        energy_points = val.energy_points;
    }
    return *this;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}
