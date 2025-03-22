#pragma once
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
class Bureaucrat;

class Form
{
public:
    Form();
    Form(const std::string &name, int grade_to_sign, int grade_to_execute);
    ~Form();
    Form(const Form &val);
    Form &operator=(const Form &val);
    std::string getName() const;
    size_t getGrade() const;
    void signForm();
    bool isSigned() const;
    void beSigned(Bureaucrat &bureaucrat);
private:
    const std::string name_;
    const size_t grade_to_sign_;
    const size_t grade_to_execute_;
    bool signed_;

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Form &form);