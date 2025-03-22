#pragma once
#include <iostream>
#include "Brain.hpp"

class Animal {
public:
    Animal();
    Animal(const Animal& val);
    Animal& operator=(const Animal& val);
    virtual ~Animal();
    virtual void makeSound() const;
    virtual std::string getType() const;
    virtual Brain* getBrain() const = 0;
protected:
    std::string type;
};
