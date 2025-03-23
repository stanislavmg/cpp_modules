#include "Span.hpp"

Span::Span(unsigned n) : size_(n), set_(), min_interval_(std::numeric_limits<int>::max()){}

Span::Span(const Span &src) : size_(src.size_), set_(src.set_), min_interval_(src.min_interval_) {}

Span::~Span() {}

Span &Span::operator=(const Span &rhs) {
  if (this != &rhs) {
    size_ = rhs.size_;
    set_ = rhs.set_;
  }
  return *this;
}

void Span::addNumber(int n) {
  if (set_.size() == size_)
    throw std::out_of_range("Container is full");
  if (!set_.empty()) {
    std::set<int>::iterator it = set_.lower_bound(n);

    if (it != set_.end())
      min_interval_ = std::min(min_interval_, *it - n);
    if (it != set_.begin()) {
      --it;
      min_interval_ = std::min(min_interval_, n - *it);
    }
  }
  set_.insert(n);
}

int Span::shortestSpan() const {
  if (set_.size() < 2)
    throw std::out_of_range("Not enough elements");
  return min_interval_;
}

int Span::longestSpan() const {
  if (set_.size() < 2)
    throw std::out_of_range("Not enough elements");
  return *set_.rbegin() - *set_.begin();
}

void Span::fillSpan() {
  srand(time(nullptr));
  while (set_.size() < size_)
    set_.insert(rand());
}
