
#ifndef A_HPP
#define A_HPP

#include "Base.hpp"

class A : public Base
{
private:
    A(const A &other);
    A &operator=(const A &other);

public:
    A();
    ~A();
};

#endif