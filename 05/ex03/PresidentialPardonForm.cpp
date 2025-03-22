#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("Presidential Pardon Form", 25, 5), target_(target) {}

    PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), target_(other.target_) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
  if (this != &other) {
    target_ = other.target_;
  }
  return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
  AForm::execute(executor);
  std::cout << target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
