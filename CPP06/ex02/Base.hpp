
#ifndef BASE_HPP
#define BASE_HPP

#include "iostream"
#include "string"
#include <cstdlib>
#include <ctime>
#include <typeinfo>

class Base
{
private:
    Base(const Base &other);
    Base &operator=(const Base &other);

public:
    Base();
    virtual ~Base();
    // member
    Base *generate();
    void identify(Base *p);
    void identify(Base &p);
};

#endif