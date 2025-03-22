#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) { *this = other; }

Intern &Intern::operator=(const Intern &other) {
  if (this != &other) {
  }
  return *this;
}

Intern::~Intern() {}

AForm *Intern::createPresidentialForm(const std::string &target) {
  return new PresidentialPardonForm(target);
}

AForm *Intern::createRobotomyForm(const std::string &target) {
  return new RobotomyRequestForm(target);
}

AForm *Intern::createShrubberyForm(const std::string &target) {
  return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(const std::string &formName,
                        const std::string &target) {
    const Intern::FormTypeMapping formTypes[] = {
        {Intern::createRobotomyForm, "robotomy request"},
        {Intern::createPresidentialForm, "presidential pardon"},
        {Intern::createShrubberyForm, "shrubbery creation"}};
                            
  for (size_t i = 0; i < 3; ++i) {
    if (formTypes[i].name == formName) {
      return formTypes[i].type(target);
    }
  }
  throw FormNotFoundException();
  return nullptr;
}

const char *Intern::FormNotFoundException::what() const throw() {
  return "Form not found";
}
