#pragma once
#include <string>
#include <stack>

class RPN {
public:
    RPN();
    ~RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    int evaluateRPN(const std::string &expression);
  private:
    bool isOperator(const std::string &token) const;
    int applyOperation(int a, int b, const std::string &op) const;
    std::stack<int> stack_;
};
