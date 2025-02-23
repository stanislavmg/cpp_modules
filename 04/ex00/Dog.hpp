#pragma once
#include "Animal.hpp"

class Dog : public Animal {
public:
  Dog();
  Dog(const Dog &val);
  Dog &operator=(const Dog &val);
  virtual ~Dog();
  virtual void makeSound() const;
  std::string getType() const;
};