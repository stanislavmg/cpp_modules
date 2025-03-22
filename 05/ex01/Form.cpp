#include "Form.hpp"

Form::Form()
    : name_(""), grade_to_sign_(150), grade_to_execute_(150), signed_(false) {}

Form::Form(const std::string &name, int grade_to_sign, int grade_to_execute)
    : name_(name), grade_to_sign_(grade_to_sign),
      grade_to_execute_(grade_to_execute), signed_(false) {
  if (grade_to_sign_ < 1 || grade_to_execute_ < 1)
    throw GradeTooHighException();
  if (grade_to_sign_ > 150 || grade_to_execute_ > 150)
    throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form &val)
    : name_(val.name_), grade_to_sign_(val.grade_to_sign_),
      grade_to_execute_(val.grade_to_execute_), signed_(val.signed_) {}

Form &Form::operator=(const Form &val) {
  if (this != &val)
    signed_ = val.signed_;
  return *this;
}

std::string Form::getName() const { return name_; }

size_t Form::getGrade() const { return grade_to_sign_; }

bool Form::isSigned() const { return signed_; }

void Form::signForm() { signed_ = true; }

void Form::beSigned(Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > grade_to_sign_)
    throw GradeTooLowException();
  signForm();
}

const char *Form::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
  os << "Form " << form.getName() << " has grade " << form.getGrade()
     << " to sign and grade " << form.getGrade() << " to execute";
  return os;
}
