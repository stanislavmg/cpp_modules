#include "RPN.hpp"
#include <sstream>

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) {
  (void)other;
}

RPN &RPN::operator=(const RPN &other) {
  (void)other;
  return *this;
}

bool RPN::isOperator(const std::string &token) const {
  return token == "+" || token == "-" || token == "*" || token == "/";
}

int RPN::applyOperation(int a, int b, const std::string &op) const {
  switch (op[0]) {
  case '+':
    return a + b;
  case '-':
    return a - b;
  case '*':
    return a * b;
  case '/':
    if (b == 0)
      throw std::runtime_error("Error: Division by zero");
    return a / b;
  default:
    throw std::runtime_error("Error: Invalid operator");
  }
}

int RPN::evaluateRPN(const std::string &expression) {
  std::istringstream iss(expression);
  std::string token;

  while (iss >> token) {
    if (isOperator(token)) {
      if (stack_.size() < 2)
        throw std::runtime_error("Error: Not enough operands");
      int b = stack_.top();
      stack_.pop();
      int a = stack_.top();
      stack_.pop();
      stack_.push(applyOperation(a, b, token));
    } else {
      for (size_t i = 0; i < token.size(); i++)
        if (!std::isdigit(token[i]))
          throw std::runtime_error("Error: Invalid token: " + token);
      stack_.push(std::atoi(token.c_str()));
    }
  }
  if (stack_.size() != 1)
    throw std::runtime_error("Error: Invalid expression");
  return stack_.top();
}
