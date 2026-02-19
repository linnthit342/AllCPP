
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base() {}

Base::~Base() {}

Base *Base::generate()
{
    static bool seeded = false;
    if (!seeded)
    {
        std::srand(std::time(NULL));
        seeded = true;
    }
    int i = std::rand() % 3;
    if (i == 0)
        return new A();
    else if (i == 1)
        return new B();
    else
        return new C();
}

void Base::identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "p: \"A\"\n";
    else if (dynamic_cast<B *>(p))
        std::cout << "p: \"B\"\n";
    else if (dynamic_cast<C *>(p))
        std::cout << "p: \"C\"\n";
}

void Base::identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "p: \"A\"\n";
        return;
    }
    catch (...)
    {
    }
    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "p: \"B\"\n";
        return;
    }
    catch (...)
    {
    }
    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "p: \"C\"\n";
        return;
    }
    catch (...)
    {
    }
}
