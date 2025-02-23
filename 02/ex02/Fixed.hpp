#pragma once
#include <iostream>

class Fixed {
public:
  Fixed();
  Fixed(const int num);
  Fixed(const float num);
  ~Fixed();
  Fixed(const Fixed &num);
  Fixed &operator=(const Fixed &num);
  int getRawBits(void) const;
  void setRawBits(int raw);
  float toFloat() const;
  int toInt() const;

  bool operator>(const Fixed &rhs) const;
  bool operator<(const Fixed &rhs) const;
  bool operator>=(const Fixed &rhs) const;
  bool operator<=(const Fixed &rhs) const;
  bool operator==(const Fixed &rhs) const;
  bool operator!=(const Fixed &rhs) const;

  Fixed operator+(const Fixed &rhs) const;
  Fixed operator-(const Fixed &rhs) const;
  Fixed operator*(const Fixed &rhs) const;
  Fixed operator/(const Fixed &rhs) const;

  Fixed &operator++();
  Fixed operator++(int);
  Fixed &operator--();
  Fixed operator--(int);

  static Fixed &min(Fixed &a, Fixed &b);
  static const Fixed &min(const Fixed &a, const Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);
  static const Fixed &max(const Fixed &a, const Fixed &b);

private:
  int fixed_point;
  static const int fractional_bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &num);
