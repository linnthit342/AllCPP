#include <iostream>
#include <string>
#include "whatever.hpp"

int main(void)
{
    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
    int e = 42;
    int f = 42;
    std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
    std::cout << "max(e, f) = " << ::max(e, f) << std::endl;
    double x = 1.234;
    double y = 5.678;
    ::swap(x, y);
    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
    std::cout << "max(x, y) = " << ::max(x, y) << std::endl;
    char ch1 = 'A';
    char ch2 = 'Z';
    ::swap(ch1, ch2);
    std::cout << "ch1 = " << ch1 << ", ch2 = " << ch2 << std::endl;
    std::cout << "min(ch1, ch2) = " << ::min(ch1, ch2) << std::endl;
    std::cout << "max(ch1, ch2) = " << ::max(ch1, ch2) << std::endl;
    return 0;
}