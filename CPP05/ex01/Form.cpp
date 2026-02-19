#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Default Form constructor\n";
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150)
        throw GradeTooLowException();
    if (gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << "Form " << _name << " constructor\n";
}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << "Form copy constructor\n";
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

Form::~Form()
{
    std::cout << "Form destructor\n";
}

const std::string& Form::getName() const
{
    return _name;
}

bool Form::getIsSigned() const
{
    return _isSigned;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form Grade is too low!";
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= _gradeToSign)
        _isSigned = true;
    else
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
    out << "Form \"" << f.getName() << "\", signed: " 
        << (f.getIsSigned() ? "yes" : "no") 
        << ", grade required to sign: " << f.getGradeToSign() 
        << ", grade required to execute: " << f.getGradeToExecute();
    return out;
}
