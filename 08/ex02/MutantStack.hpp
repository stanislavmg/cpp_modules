#pragma once
#include <deque>
#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
public:
  MutantStack();
  MutantStack(const MutantStack &src);
  ~MutantStack();
  MutantStack &operator=(const MutantStack &rhs);
  typedef typename std::deque<T>::iterator iterator;
  typedef typename std::deque<T>::const_iterator const_iterator;
  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;
};

template <typename T> MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &src) : std::stack<T>(src) {}

template <typename T> MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &rhs) {
  if (this != &rhs)
    std::stack<T>::operator=(rhs);
  return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
  return std::stack<T>::c.begin();
}

template <typename T> typename MutantStack<T>::iterator MutantStack<T>::end() {
  return std::stack<T>::c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
  return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
  return std::stack<T>::c.end();
}
