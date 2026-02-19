#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat alice("Alice", 50);
        Bureaucrat bob("Bob", 120);
        Form formA("Top Secret Form", 75, 50);
        Form formB("Basic Form", 130, 100);

        std::cout << formA << std::endl;
        std::cout << formB << std::endl;

        std::cout << "\n--- Attempting to sign forms ---" << std::endl;

        // Bob tries to sign formA → should fail
        bob.signForm(formA);

        // Alice signs formA → should succeed
        alice.signForm(formA);

        // Bob signs formB → should succeed
        bob.signForm(formB);

        std::cout << "\n--- Final form statuses ---" << std::endl;
        std::cout << formA << std::endl;
        std::cout << formB << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
