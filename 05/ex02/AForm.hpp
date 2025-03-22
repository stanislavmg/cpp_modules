#pragma once
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
class Bureaucrat;

class AForm
{
public:
    AForm();
    AForm(const std::string &name, int grade_to_sign, int grade_to_execute);
    virtual ~AForm();
    AForm(const AForm &val);
    AForm &operator=(const AForm &val);
    std::string getName() const;
    size_t getGrade() const;
    virtual void signForm();
    virtual void execute(const Bureaucrat &executor) const = 0;
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
    class NotSignedException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const AForm &AForm);