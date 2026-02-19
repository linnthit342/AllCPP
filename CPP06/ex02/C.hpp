
#ifndef C_HPP
#define C_HPP

#include "Base.hpp"

class C : public Base
{
private:
    C(const C &other);
    C &operator=(const C &other);

public:
    C();
    ~C();
};

#endif