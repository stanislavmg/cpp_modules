#include "WrongDog.hpp"

WrongDog::WrongDog() : WrongAnimal() {
  std::cout << "WrongDog default constructor called" << std::endl;
  type = "WrongDog";
}

WrongDog::~WrongDog() {
  std::cout << "WrongDog destructor called" << std::endl;
}

WrongDog::WrongDog(const WrongDog &val) {
  std::cout << "WrongDog copy constructor called" << std::endl;
  *this = val;
}

WrongDog &WrongDog::operator=(const WrongDog &val) {
  std::cout << "WrongDog copy assignment operator called" << std::endl;
  if (this != &val) {
    type = val.type;
  }
  return *this;
}

void WrongDog::makeSound() const {
  std::cout << "WrongDog Woof Woof" << std::endl;
}

std::string WrongDog::getType() const { return type; }
