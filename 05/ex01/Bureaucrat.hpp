#pragma once
#include "Form.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
class Form;
class Bureaucrat {
public:
  Bureaucrat();
  Bureaucrat(const std::string &name, size_t grade = 150);
  ~Bureaucrat();
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat operator=(const Bureaucrat &other);

  std::string getName() const;
  size_t getGrade() const;
  void incrementGrade();
  void decrementGrade();
  void signForm(Form &form);

private:
  std::string name_;
  size_t grade_;
  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
