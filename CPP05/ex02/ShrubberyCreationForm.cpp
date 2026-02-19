#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
    std::cout << "Default shrubbery creation form\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << _target << " shrubbery creation form\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target)
{
    std::cout << _target << " copied shrubbery creation form\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    std::cout << _target << " assigned shrubbery creation form\n";
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << _target << " destroy shrubbery creation form\n";
}

const std::string &ShrubberyCreationForm::getTarget() const
{
    return _target;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (!getIsSigned())
        throw FormNotSign();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file.is_open())
        throw std::runtime_error("Failed to create shrubbery file!");

    file << "     ccee88oo\n";
    file << "  C8O8O8Q8PoOb o8oo\n";
    file << " dOB69QO8PdUOpugoO9bD\n";
    file << "CgggbU8OU qOp qOdoUOdcb\n";
    file << "    6OuU  /p u gcoUodpP\n";
    file << "      \\\\//  /douUP\n";
    file << "        \\\\\\\\\n";
    file << "         |||/\\\n";
    file << "         |||\\/\n";
    file << "         |||||\n";
    file << "   .....//||||\\....\n";

    file.close();
}
