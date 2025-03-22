#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
  std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &val) {
  std::cout << "WrongAnimal copy constructor called" << std::endl;
  *this = val;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &val) {
  std::cout << "WrongAnimal copy assignment operator called" << std::endl;
  if (this != &val) {
    type = val.type;
  }
  return *this;
}

void WrongAnimal::makeSound() const {
  std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const { return type; }