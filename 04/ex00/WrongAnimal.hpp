#pragma once
#include <iostream>

class WrongAnimal {
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &val);
    WrongAnimal &operator=(const WrongAnimal &val);
    virtual ~WrongAnimal();
    virtual void makeSound() const;
    virtual std::string getType() const;
protected:
    std::string type;
};