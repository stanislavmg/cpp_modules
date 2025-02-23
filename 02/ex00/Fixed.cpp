#include "Fixed.hpp"

Fixed::Fixed() : fixed_point(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed::Fixed(const Fixed &num) {
  std::cout << "Copy constructor called" << std::endl;
  *this = num;
}

Fixed &Fixed::operator=(const Fixed &num) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &num) {
    fixed_point = num.fixed_point;
  }
  return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return fixed_point;
}

void Fixed::setRawBits(int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	fixed_point = raw;
}

