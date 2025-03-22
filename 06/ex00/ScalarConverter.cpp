#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
  *this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
  (void)other;
  return *this;
}

ScalarConverter::~ScalarConverter() {}

void printSpecialSymbol(const std::string &input) {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  if (input.find("nan") != std::string::npos) {
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
  } else {
    std::string sign;
    if (input.front() == '+' || input.front() == '-')
      sign = input.front();
    std::cout << "float: " << sign << "inff" << std::endl;
    std::cout << "double: " << sign << "inf" << std::endl;
  }
}

bool isValidInput(const std::string &input) {
  size_t i = 0;
  if (input[i] == '+' || input[i] == '-')
    i++;
  bool hasDigits = false;
  while (i < input.size() && std::isdigit(input[i])) {
    i++;
    hasDigits = true;
  }
  if (hasDigits && i < input.size() && input[i] == '.') {
    i++;
    if (!std::isdigit(input[i]))
      return false;
  }
  while (i < input.size() && std::isdigit(input[i])) {
    i++;
    hasDigits = true;
  }
  if (i < input.size() && input[i] == 'f')
    i++;
  return hasDigits && i == input.size();
}

void ScalarConverter::convert(const std::string &input) {
  if (input.empty()) {
    std::cerr << "Error: empty input" << std::endl;
    return;
  }
  bool is_nan = input == "nan" || input == "nanf";
  bool is_inf = input == "inf" || input == "inff" || input == "+inf" ||
                input == "+inff" || input == "-inf" || input == "-inff";
  if (is_nan || is_inf)
    return printSpecialSymbol(input);

  if (input.size() == 1 && !std::isdigit(input.front()))
    return printConvertedInput(input.front());

  if (!isValidInput(input)) {
    std::cerr << "Error: invalid input" << std::endl;
    return;
  }

  if (input.back() == 'f' && input.find('.') != std::string::npos) {
    float num(std::stof(input));
    printConvertedInput(num);
  } else if (input.find('.') != std::string::npos) {
    double num(std::stod(input));
    printConvertedInput(num);
  } else {
    int num(std::stoi(input));
    printConvertedInput(num);
  }
}
