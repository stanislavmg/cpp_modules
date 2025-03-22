#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
  std::cout << "WrongCat default constructor called" << std::endl;
  type = "WrongCat";
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &val) {
  std::cout << "WrongCat copy constructor called" << std::endl;
  *this = val;
}

WrongCat &WrongCat::operator=(const WrongCat &val) {
  std::cout << "WrongCat copy assignment operator called" << std::endl;
  if (this != &val) {
    type = val.type;
  }
  return *this;
}

void WrongCat::makeSound() const {
  std::cout << "WrongCat Meow Meow" << std::endl;
}

std::string WrongCat::getType() const { return type; }
