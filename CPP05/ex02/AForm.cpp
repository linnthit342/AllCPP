#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Default AForm constructor\n";
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150)
        throw GradeTooLowException();
    if (gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << "AForm " << _name << " constructor\n";
}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << "AForm copy constructor\n";
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

AForm::~AForm()
{
    std::cout << "AForm destructor\n";
}

const std::string& AForm::getName() const
{
    return _name;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm Grade is too low!";
}

const char* AForm::FormNotSign::what() const throw()
{
    return "AForm is not sign!";
};

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= _gradeToSign)
        _isSigned = true;
    else
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
    out << "AForm \"" << f.getName() << "\", signed: " 
        << (f.getIsSigned() ? "yes" : "no") 
        << ", grade required to sign: " << f.getGradeToSign() 
        << ", grade required to execute: " << f.getGradeToExecute();
    return out;
}
