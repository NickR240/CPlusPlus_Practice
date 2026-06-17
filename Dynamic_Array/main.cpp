#include <iostream>
#include "dynamic_array.h"

int main()
{
    DynamicArray<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(354);

    std::cout << "Size: " << numbers.size() << '\n';
    std::cout << "Capacity: " << numbers.capacity() << '\n';
    std::cout << "First value: " << numbers[0] << '\n';
    std::cout << "Second value: " << numbers[1] << '\n';
    std::cout << "Third value: " << numbers[2] << '\n';

    numbers[0] = 50;

    std::cout << "Changed value: " << numbers[0] << '\n';

    return 0;
}
