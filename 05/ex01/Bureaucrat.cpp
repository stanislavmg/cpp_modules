#include "Bureaucrat.hpp"
#include "Form.hpp"

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

void Bureaucrat::signForm(Form &form) {
  try {
    form.beSigned(*this);
    std::cout << name_ << " signs " << form.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << name_ << " cannot sign " << form.getName() << " because "
              << e.what() << std::endl;
  }
}
const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}
const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
  return os;
}
