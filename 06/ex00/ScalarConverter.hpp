#pragma once
#include <iostream>

class ScalarConverter {
public:
  ScalarConverter();
  ScalarConverter(const ScalarConverter &other);
  ScalarConverter &operator=(const ScalarConverter &other);
  ~ScalarConverter();
  static void convert(const std::string &input);
};

template <typename T> void printConvertedInput(T num) {
  char ch(static_cast<char>(num));
  if (num > std::numeric_limits<char>::max() ||
      num < std::numeric_limits<char>::lowest()) {
    std::cout << "char: impossible" << std::endl;
  } else if (std::isprint(ch)) {
    std::cout << "char: " << "'" << ch << "'" << std::endl;
  } else {
    std::cout << "char: Non displayable" << std::endl;
  }

  if (num > std::numeric_limits<int>::max() ||
      num < std::numeric_limits<int>::lowest()) {
    std::cout << "int: impossible" << std::endl;
  } else {
    std::cout << "int: " << static_cast<int>(num) << std::endl;
  }
  std::cout << std::fixed;
  if (num > std::numeric_limits<float>::max() ||
      num < std::numeric_limits<float>::lowest()) {
    std::cout << "float: impossible" << std::endl;
  } else {
    std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
  }
  std::cout << "double: " << static_cast<double>(num) << std::endl;
}
