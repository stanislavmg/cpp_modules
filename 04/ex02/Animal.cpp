#include "Animal.hpp"

Animal::Animal() : type("Animal") {
  std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

Animal::Animal(const Animal &val) {
  std::cout << "Animal copy constructor called" << std::endl;
  *this = val;
}

Animal &Animal::operator=(const Animal &val) {
  std::cout << "Animal copy assignment operator called" << std::endl;
  if (this != &val) {
    type = val.type;
  }
  return *this;
}