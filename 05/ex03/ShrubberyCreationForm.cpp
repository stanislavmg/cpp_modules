#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery Creation", 145, 137), target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target_(other.target_) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  if (this != &other) {
    target_ = other.target_;
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
  AForm::execute(executor);
  std::ofstream outfile(target_ + "_shrubbery");
  outfile << "       _-_\n"
          << "    /~~   ~~\\\n"
          << " /~~         ~~\\\n"
          << "{               }\n"
          << " \\  _-     -_  /\n"
          << "   ~  \\\\ //  ~\n"
          << "_- -   | | _- _\n"
          << "  _ -  | |   -_\n"
          << "      // \\\\\n";
  outfile.close();
}