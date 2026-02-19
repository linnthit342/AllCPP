#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
    std::cout << "Default RobotomyRequestForm\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << _target << " RobotomyRequestForm created\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target)
{
    std::cout << _target << " copied RobotomyRequestForm\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    std::cout << _target << " assigned RobotomyRequestForm\n";
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << _target << " destroy RobotomyRequestForm\n";
}

const std::string &RobotomyRequestForm::getTarget() const
{
    return _target;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (!getIsSigned())
        throw FormNotSign();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();
    static bool seeded = false;
    if (!seeded)
    {
        std::srand(std::time(NULL));
        seeded = true;
    }
    std::cout << "*Drilling noises* Bzzzzz..." << std::endl;
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << _target << "!" << std::endl;
}
