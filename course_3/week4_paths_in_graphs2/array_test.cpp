#include <iostream>
#include <immintrin.h>

int main()
{
    double* my_array;
    std::cout << "Enter a positive integer: ";
    int length{};
    std::cin >> length;

    my_array = new double[length]{};
    for (int i = 0; i < length; ++i)
    {
        my_array[i] = i;
        std::cout << my_array[i] << " ";
    }
    std::cout << "\n";
    delete []my_array;
    my_array = nullptr;
    return 0;
}