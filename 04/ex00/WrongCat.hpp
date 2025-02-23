#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
  WrongCat();
  WrongCat(const WrongCat &val);
  WrongCat &operator=(const WrongCat &val);
  virtual ~WrongCat();
  virtual void makeSound() const;
  std::string getType() const;
};