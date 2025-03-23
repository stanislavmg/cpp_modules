#pragma once
#include <set>

class Span {
public:
  Span(unsigned n);
  Span(const Span &src);
  ~Span();
  Span &operator=(const Span &rhs);
  void addNumber(int n);
  int shortestSpan() const;
  int longestSpan() const;
  void fillSpan();
private:
  unsigned size_;
  std::multiset<int> set_;
  int min_interval_;
};
