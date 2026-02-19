#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern created\n";
}

Intern::Intern(const Intern& other) { (void)other; }

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destroyed\n";
}
AForm* Intern::createShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPardon(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

// AForm* Intern::makeForm(std::string formName, std::string target)
// {
//     std::string names[3] = {
//         "shrubbery creation",
//         "robotomy request",
//         "presidential pardon"
//     };

//     AForm* forms[3] = {
//         new ShrubberyCreationForm(target),
//         new RobotomyRequestForm(target),
//         new PresidentialPardonForm(target)
//     };
//     for (int i = 0; i < 3; i++)
//     {
//         if (formName == names[i])
//         {
//             std::cout << "Intern creates " << names[i] << std::endl;
//             for (int j = 0; j < 3; j++)
//             {
//                 if (j != i)
//                     delete forms[j];
//             }
//             return forms[i];
//         }
//     }
//     std::cout << "Intern cannot create form: " << formName << std::endl;
//     for (int i = 0; i < 3; i++)
//         delete forms[i];
//     return NULL;
// }

AForm* Intern::makeForm(std::string formName, std::string target)
{
    std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*creators[3])(const std::string&) = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPardon
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == names[i])
        {
            std::cout << "Intern creates " << names[i] << std::endl;
            return creators[i](target);
        }
    }

    std::cout << "Intern cannot create form: " << formName << std::endl;
    return NULL;
}
