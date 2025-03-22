#pragma once

#include <iostream>
#include <string>


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
private:
  std::string name_;
  size_t grade_;
  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade is too high"; }
  };
  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade is too low"; }
  };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
