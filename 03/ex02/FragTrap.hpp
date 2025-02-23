#pragma once
#include "ClapTrap.hpp"


class FragTrap : public ClapTrap {
public:
    FragTrap();
    FragTrap(const std::string &val);
    virtual ~FragTrap();
    FragTrap(const FragTrap &val);
    FragTrap &operator=(const FragTrap &val);
    void highFivesGuys(void);
};

