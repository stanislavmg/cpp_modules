#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_(""), grade_(150) {}
Bureaucrat::Bureaucrat(const std::string &name, size_t grade)
    : name_(name), grade_(grade) {}
Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name_(other.name_), grade_(other.grade_) {}
Bureaucrat Bureaucrat::operator=(const Bureaucrat &other) {
  if (this != &other) {
    name_ = other.name_;
    grade_ = other.grade_;
  }
  return *this;
}
std::string Bureaucrat::getName() const { return name_; }
size_t Bureaucrat::getGrade() const { return grade_; }
void Bureaucrat::incrementGrade() {
  if (grade_ == 1)
    throw GradeTooHighException();
  grade_--;
}
void Bureaucrat::decrementGrade() {
  if (grade_ == 150)
    throw GradeTooLowException();
  grade_++;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
  return os;
}
