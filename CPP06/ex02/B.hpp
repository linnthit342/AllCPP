
#ifndef B_HPP
#define B_HPP

#include "Base.hpp"

class B : public Base
{
private:
    B(const B &other);
    B &operator=(const B &other);

public:
    B();
    ~B();
};

#endif