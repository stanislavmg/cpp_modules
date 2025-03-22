#include "AForm.hpp"

AForm::AForm()
    : name_(""), grade_to_sign_(150), grade_to_execute_(150), signed_(false) {}

AForm::AForm(const std::string &name, int grade_to_sign, int grade_to_execute)
    : name_(name), grade_to_sign_(grade_to_sign),
      grade_to_execute_(grade_to_execute), signed_(false) {
  if (grade_to_sign_ < 1 || grade_to_execute_ < 1)
    throw GradeTooHighException();
  if (grade_to_sign_ > 150 || grade_to_execute_ > 150)
    throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm &val)
    : name_(val.name_), grade_to_sign_(val.grade_to_sign_),
      grade_to_execute_(val.grade_to_execute_), signed_(val.signed_) {}

AForm &AForm::operator=(const AForm &val) {
  if (this != &val)
    signed_ = val.signed_;
  return *this;
}

std::string AForm::getName() const { return name_; }

size_t AForm::getGrade() const { return grade_to_sign_; }

bool AForm::isSigned() const { return signed_; }

void AForm::signForm() { signed_ = true; }

void AForm::beSigned(Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > grade_to_sign_)
    throw GradeTooLowException();
  signForm();
}

void AForm::execute(const Bureaucrat &executor) const {
  if (!signed_)
    throw NotSignedException();
  if (executor.getGrade() > grade_to_execute_)
    throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

const char *AForm::NotSignedException::what() const throw() {
  return "AForm is not signed";
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm) {
  os << "AForm " << AForm.getName() << " has grade " << AForm.getGrade()
     << " to sign and grade " << AForm.getGrade() << " to execute";
  return os;
}
