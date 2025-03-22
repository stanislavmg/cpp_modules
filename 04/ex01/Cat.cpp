#include "Cat.hpp"

Cat::Cat() : Animal() {
  std::cout << "Cat default constructor called" << std::endl;
  type = "Cat";
  brain = new Brain();
}

Cat::~Cat() { 
  std::cout << "Cat destructor called" << std::endl; 
  delete brain;
}

Cat::Cat(const Cat &val) {
  std::cout << "Cat copy constructor called" << std::endl;
  *this = val;
}

Cat &Cat::operator=(const Cat &val) {
  std::cout << "Cat copy assignment operator called" << std::endl;
  if (this != &val) {
    type = val.type;
    delete brain;
    brain = new Brain(*val.brain);
  }
  return *this;
}

void Cat::makeSound() const { std::cout << "Meow Meow" << std::endl; }

std::string Cat::getType() const { return type; }

Brain *Cat::getBrain() const { return brain; }