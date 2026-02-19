
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Alex", 2);
        std::cout << a << std::endl;
        a.incrementGrade();
        std::cout << a << std::endl;
        a.incrementGrade();
        std::cout << a << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "-------------------------" << std::endl;
    try
    {
        Bureaucrat b("Bob", 149);
        std::cout << b << std::endl;
        b.decrementGrade();
        std::cout << b << std::endl;
        b.decrementGrade();
        std::cout << b << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "-------------------------" << std::endl;
    try
    {
        Bureaucrat c("Charlie", 151);
        std::cout << c << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
