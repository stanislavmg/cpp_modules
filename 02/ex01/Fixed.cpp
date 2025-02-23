#include "Fixed.hpp"

Fixed::Fixed() : fixed_point(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) : fixed_point(num << fractional_bits) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num)
    : fixed_point(roundf(num * (1 << fractional_bits))) {
  std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat() const {
  return static_cast<float>(fixed_point) / (1 << fractional_bits);
}

int Fixed::toInt() const { return fixed_point >> fractional_bits; }

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

std::ostream &operator<<(std::ostream &out, const Fixed &num) {
  out << num.toFloat();
  return out;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return fixed_point;
}

void Fixed::setRawBits(int raw) {
  std::cout << "setRawBits member function called" << std::endl;
  fixed_point = raw;
}
