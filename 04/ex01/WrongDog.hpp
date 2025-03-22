#pragma once
#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal {
public:
    WrongDog();
    WrongDog(const WrongDog &val);
    WrongDog &operator=(const WrongDog &val);
    virtual ~WrongDog();
    virtual void makeSound() const;
    std::string getType() const;
};