#include <iostream>
#include <string>
#include "iter.hpp"

// print function
template <typename T>
void print(const T &x)
{
    std::cout << x << std::endl;
}

// increment function for non-const arrays
void increment(int &x)
{
    x += 1;
    std::cout << "inc: " << x << std::endl;
}

int main(void)
{
    std::cout << "--- int array ---" << std::endl;
    int arr1[5] = {1, 2, 3, 4, 5};
    iter(arr1, 5, print<int>);

    std::cout << "\n--- increment array elements ---" << std::endl;
    iter(arr1, 5, increment);
    iter(arr1, 5, print<int>);

    std::cout << "\n--- string array ---" << std::endl;
    std::string arr2[3] = {"hello", "templates", "42"};
    iter(arr2, 3, print<std::string>);

    std::cout << "\n--- const array ---" << std::endl;
    const int arr3[4] = {10, 20, 30, 40};
    iter(arr3, 4, print<int>); // works because print takes const T&

    return 0;
}
