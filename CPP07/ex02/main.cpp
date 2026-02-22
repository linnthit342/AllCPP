#include "Array.hpp"
#include <iostream>

int main()
{
    try
    {
        Array<int> arr(5); // array of 5 integers
        for (unsigned int i = 0; i < arr.size(); i++)
            arr[i] = i * 10;

        std::cout << "Original array: ";
        for (unsigned int i = 0; i < arr.size(); i++)
            std::cout << arr[i] << " ";
        std::cout << std::endl;

        Array<int> copy = arr; // copy constructor
        copy[0] = 999;         // modify copy
        std::cout << "After modifying copy:" << std::endl;
        std::cout << "Original: " << arr[0] << std::endl; // should remain 0
        std::cout << "Copy: " << copy[0] << std::endl;    // should be 999

        // Access out-of-bounds
        std::cout << arr[10] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
