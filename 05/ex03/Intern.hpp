#pragma once
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
public:
  Intern();
  Intern(const Intern &other);
  Intern &operator=(const Intern &other);
  ~Intern();

  AForm *makeForm(const std::string &formName, const std::string &target);
  static AForm *createPresidentialForm(const std::string &target);
  static AForm *createRobotomyForm(const std::string &target);
  static AForm *createShrubberyForm(const std::string &target);

private:
  class FormNotFoundException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  struct FormTypeMapping {
    AForm *(*type)(const std::string &);
    const char *name;
  };
};

