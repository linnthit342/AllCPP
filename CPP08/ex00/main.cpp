#include <iostream>
#include <vector>
#include <list>
#include <deque>

#include "easyfind.hpp"

int main()
{
    try
    {
        std::vector<int> v;
        for (int i = 0; i < 10; ++i)
            v.push_back(i * 2);

        std::cout << "Vector: searching 6..." << std::endl;
        std::vector<int>::iterator vit = easyfind(v, 6);
        std::cout << "Found: " << *vit << std::endl;

        std::cout << "Vector: searching 7 (should throw)..." << std::endl;
        easyfind(v, 7);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        std::list<int> l;
        l.push_back(42);
        l.push_back(21);

        std::cout << "List: searching 21..." << std::endl;
        std::list<int>::iterator lit = easyfind(l, 21);
        std::cout << "Found: " << *lit << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        std::deque<int> d;
        d.push_back(5);
        d.push_back(10);

        std::cout << "Deque (const): searching 5..." << std::endl;
        const std::deque<int> cd = d;
        std::deque<int>::const_iterator cit = easyfind(cd, 5);
        std::cout << "Found: " << *cit << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
