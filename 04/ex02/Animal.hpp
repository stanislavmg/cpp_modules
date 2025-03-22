#pragma once
#include <iostream>
#include "Brain.hpp"

class Animal {
public:
    Animal();
    Animal(const Animal& val);
    Animal& operator=(const Animal& val);
    virtual ~Animal() = 0;
    virtual void makeSound() const = 0;
    virtual std::string getType() const = 0;
    virtual Brain* getBrain() const = 0;
protected:
    std::string type;
};
