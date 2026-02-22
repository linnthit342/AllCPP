#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &a, int value)
{
    typename T::iterator it = std::find(a.begin(), a.end(), value);
    if (it == a.end())
        throw std::runtime_error("Value not found");
    return it;
}
template <typename T>
typename T::const_iterator easyfind(const T &a, int value)
{
    typename T::const_iterator it = std::find(a.begin(), a.end(), value);
    if (it == a.end())
        throw std::runtime_error("Value not found");
    return it;
}

#endif