
#include "Base.hpp"

int main()
{
    for (int i = 0; i < 3; i++)
    {
        Base b;
        Base *p = b.generate();
        std::cout << "\nPointer Identify\n";
        p->identify(p);
        std::cout << "\nReference Identify\n";
        p->identify(*p);
        delete p;
    }
}