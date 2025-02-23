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

bool Fixed::operator>(const Fixed &rhs) const { return fixed_point > rhs.fixed_point; }
bool Fixed::operator<(const Fixed &rhs) const { return fixed_point < rhs.fixed_point; }
bool Fixed::operator>=(const Fixed &rhs) const { return fixed_point >= rhs.fixed_point; }
bool Fixed::operator<=(const Fixed &rhs) const { return fixed_point <= rhs.fixed_point; }
bool Fixed::operator==(const Fixed &rhs) const { return fixed_point == rhs.fixed_point; }
bool Fixed::operator!=(const Fixed &rhs) const { return fixed_point != rhs.fixed_point; }
Fixed Fixed::operator+(const Fixed &rhs) const { return this->toFloat() + rhs.toFloat(); }
Fixed Fixed::operator-(const Fixed &rhs) const { return this->toFloat() - rhs.toFloat(); }
Fixed Fixed::operator*(const Fixed &rhs) const { return this->toFloat() * rhs.toFloat(); }
Fixed Fixed::operator/(const Fixed &rhs) const { return this->toFloat() / rhs.toFloat(); }

Fixed &Fixed::operator++() {
  ++fixed_point;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed temp(*this);
  ++fixed_point;
  return temp;
}

Fixed &Fixed::operator--() {
  --fixed_point;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed temp(*this);
  --fixed_point;
  return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
  return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
  return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  return (a > b) ? a : b;
}