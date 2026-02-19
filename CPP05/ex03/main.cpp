#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat boss("Boss", 1);
        Intern intern;

        std::cout << std::endl;

        // Valid forms
        AForm* shrub;
	    shrub = intern.makeForm("shrubbery creation", "home");
        AForm* robo = intern.makeForm("robotomy request", "Bender");
        AForm* pardon = intern.makeForm("presidential pardon", "Ford Prefect");

        std::cout << std::endl;

        boss.signForm(*shrub);
        boss.executeForm(*shrub);

        std::cout << std::endl;

        boss.signForm(*robo);
        boss.executeForm(*robo);

        std::cout << std::endl;

        boss.signForm(*pardon);
        boss.executeForm(*pardon);

        std::cout << std::endl;

        // Invalid form name
        AForm* unknown = intern.makeForm("coffee request", "office");
        if (!unknown)
            std::cout << "No form created for 'coffee request'" << std::endl;

        // Cleanup
        delete shrub;
        delete robo;
        delete pardon;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
