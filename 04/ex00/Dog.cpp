#include "Dog.hpp"

Dog::Dog() : Animal() {
  std::cout << "Dog default constructor called" << std::endl;
  type = "Dog";
}

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

Dog::Dog(const Dog &val) {
  std::cout << "Dog copy constructor called" << std::endl;
  *this = val;
}

Dog &Dog::operator=(const Dog &val) {
  std::cout << "Dog copy assignment operator called" << std::endl;
  if (this != &val) {
    type = val.type;
  }
  return *this;
}

void Dog::makeSound() const { std::cout << "Woof Woof" << std::endl; }

std::string Dog::getType() const { return type; }