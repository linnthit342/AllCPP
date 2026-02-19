#include "Serialization.hpp"

int main()
{
    Data d1;
    d1.name = "Ameath";
    d1.number = 29;

    uintptr_t raw1 = Serialization::serialize(&d1);
    Data *ptr1 = Serialization::deserialize(raw1);

    std::cout << "===== Test Case 1 =====\n";
    std::cout << "Original Data address: " << &d1 << "\nname & number: " << d1.name << " " << d1.number << "\n";
    std::cout << "Serialized integer: " << raw1 << "\n";
    std::cout << "Deserialized Data pointer: " << ptr1 << "\nname & number: " << ptr1->name << " " << ptr1->number << "\n\n";

    // Empty string
    Data d2;
    d2.name = "";
    d2.number = 0;

    uintptr_t raw2 = Serialization::serialize(&d2);
    Data *ptr2 = Serialization::deserialize(raw2);

    std::cout << "===== Test Case 2 =====\n";
    std::cout << "Original Data address: " << &d2 << "\nname & number: '" << d2.name << "' " << d2.number << "\n";
    std::cout << "Serialized integer: " << raw2 << "\n";
    std::cout << "Deserialized Data pointer: " << ptr2 << "\nname & number: '" << ptr2->name << "' " << ptr2->number << "\n\n";

    return 0;
}
