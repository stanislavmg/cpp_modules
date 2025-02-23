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

private:
  int fixed_point;
  static const int fractional_bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &num);
