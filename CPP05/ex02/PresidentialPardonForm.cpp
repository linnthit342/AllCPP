#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <stdexcept>

// Default constructor
PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), _target("default")
{
    std::cout << "Default PresidentialPardonForm\n";
}

// Param constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << _target << " PresidentialPardonForm\n";
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), _target(other._target)
{
    std::cout << _target << " copied PresidentialPardonForm\n";
}

// Assignment operator
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    std::cout << _target << " assigned PresidentialPardonForm\n";
    return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << _target << " destroy PresidentialPardonForm\n";
}

// Getter
const std::string &PresidentialPardonForm::getTarget() const
{
    return _target;
}

// Execute
void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (!getIsSigned())
        throw FormNotSign();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
