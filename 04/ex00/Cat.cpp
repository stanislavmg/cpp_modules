#include "Cat.hpp"

Cat::Cat() : Animal() {
  std::cout << "Cat default constructor called" << std::endl;
  type = "Cat";
}

Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; }

Cat::Cat(const Cat &val) {
  std::cout << "Cat copy constructor called" << std::endl;
  *this = val;
}

Cat &Cat::operator=(const Cat &val) {
  std::cout << "Cat copy assignment operator called" << std::endl;
  if (this != &val) {
    type = val.type;
  }
  return *this;
}

void Cat::makeSound() const { std::cout << "Meow Meow" << std::endl; }

std::string Cat::getType() const { return type; }