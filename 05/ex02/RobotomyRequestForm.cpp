#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Robotomy Request Form", 72, 45), target_(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  if (this != &other) {
    target_ = other.target_;
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
  AForm::execute(executor);
  std::cout << "* drilling noises *" << std::endl;
  if (rand() % 2) {
    std::cout << target_ << " has been robotomized successfully" << std::endl;
  } else {
    std::cout << "Robotomy failed" << std::endl;
  }
}