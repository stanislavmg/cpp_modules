#pragma once
#include <iostream>

class Animal {
public:
    Animal();
    Animal(const Animal& val);
    Animal& operator=(const Animal& val);
    virtual ~Animal();
    virtual void makeSound() const;
    virtual std::string getType() const;
protected:
    std::string type;
};
