#pragma once

#include <iostream>

class Fixed {
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &num);
	Fixed &operator=(const Fixes &num);
	int getRawBits(void) const;
	void setRawBits(int const raw);
private:
	int fixed_point_;
	static const int bits_;
};
