#ifndef HARL_H
#define HARL_H

#include <string>
#include <iostream>

class Harl
{
	static const int size = 4;
	void	(Harl::*lvl[size])(void);

	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
public:
	Harl();
	void	complain(std::string level);
};

#endif
