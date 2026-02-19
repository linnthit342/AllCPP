#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat high("HighRank", 1);
        Bureaucrat mid("MidRank", 50);
        Bureaucrat low("LowRank", 140);

        std::cout << "=== Testing ShrubberyCreationForm ===" << std::endl;
        ShrubberyCreationForm shrub("garden");
        std::cout << shrub << std::endl;

        low.signForm(shrub);
        low.executeForm(shrub); // should fail (grade too low)
        high.executeForm(shrub); // should succeed

        std::cout << "\n=== Testing RobotomyRequestForm ===" << std::endl;
        RobotomyRequestForm robo("Bender");
        std::cout << robo << std::endl;

        mid.signForm(robo);
        high.executeForm(robo);
        high.executeForm(robo); // run twice to test random chance

        std::cout << "\n=== Testing PresidentialPardonForm ===" << std::endl;
        PresidentialPardonForm pardon("Arthur Dent");
        std::cout << pardon << std::endl;

        mid.signForm(pardon); // should fail
        high.signForm(pardon);
	    mid.executeForm(pardon);
        high.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
