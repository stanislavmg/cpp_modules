#pragma once
#include <exception>

template <typename T> class Array {
public:
  Array();
  Array(unsigned n);
  Array(const Array &src);
  ~Array();
  Array &operator=(const Array &rhs);
  T &operator[](unsigned i);
  unsigned size() const;

private:
  class OutOfRangeException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  T *array_;
  unsigned size_;
};

template <typename T> Array<T>::Array() : array_(nullptr), size_(0) {}

template <typename T>
Array<T>::Array(unsigned n) : array_(new T[n]), size_(n) {
    for (unsigned i = 0; i < size_; i++) {
        array_[i] = T();
    }
}

template <typename T>
Array<T>::Array(const Array &src)
    : array_(new T[src.size()]), size_(src.size()) {
  for (unsigned i = 0; i < size_; i++) {
    array_[i] = src.array_[i];
  }
}

template <typename T> Array<T>::~Array() { delete[] array_; }

template <typename T> Array<T> &Array<T>::operator=(const Array &rhs) {
  if (this != &rhs) {
    delete[] array_;
    array_ = new T[rhs.size_];
    size_ = rhs.size_;
    for (unsigned i = 0; i < size_; i++) {
      array_[i] = rhs.array_[i];
    }
  }
  return *this;
}

template <typename T> T &Array<T>::operator[](unsigned i) {
  if (i >= size_) {
    throw OutOfRangeException();
  }
  return array_[i];
}

template <typename T> unsigned Array<T>::size() const { return size_; }

template <typename T>
const char *Array<T>::OutOfRangeException::what() const throw() {
  return "Index out of range";
}
