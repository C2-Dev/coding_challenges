/*
Problem #2
Difficulty: HARD

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.
For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?

Chris Georgiades
04.25.19
*/

#include <iostream>

size_t aSize;

void prob2(int*, int*, size_t);

int main()
{
    std::cout << "\nWelcome to prob2!\n"
        << "Enter the size of the array: ";
    std::cin >> aSize;

    int arr[aSize];
    int dst[aSize];

    for (size_t i = 0; i < aSize; ++i)
    {
        std::cout << "Enter array element " << i << ": ";
        std::cin >> arr[i];
    }
    
    prob2(arr, dst, aSize);

    std::cout << "The new array is: ";
    for (size_t i = 0; i < aSize; ++i)
        std::cout << dst[i] << " ";

    std::cout << "\nGoodbye...\n\n";
    return 0;
}

void prob2(int* src, int* dst, size_t aSize)
{   
    for (size_t i = 0; i < aSize; ++i)
    {   
        int sum = 1;
        for (size_t j = 0; j < aSize; ++j)
        {
            if (j != i)
                sum *= src[j];
        }
        dst[i] = sum;
    }
}
