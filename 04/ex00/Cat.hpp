#pragma once
#include "Animal.hpp"

class Cat : public Animal {
public:
  Cat();
  Cat(const Cat &val);
  Cat &operator=(const Cat &val);
  virtual ~Cat();
  virtual void makeSound() const;
  std::string getType() const;
};