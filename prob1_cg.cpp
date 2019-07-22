/*
Problem #1: 
Difficulty: EASY

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?

Chris Georgiades
04.24.19

To build: g++ -o prob1.x prob1.cpp
*/

#include <iostream>
#include <list>

bool CheckForSum(int, std::list<int> &);

int main()
{
    size_t listSize = 0;
    std::list<int> l;
    std::cout << "\n  Enter list size: ";
    std::cin >> listSize;

    for (size_t i = 0; i < listSize; ++i)
    {
        int element = 0;
        std::cout << "  Enter list element " << i << ": ";
        std::cin >> element;
        l.push_back(element);
    }

    int k;
    std::cout << "\n  Enter the sum you wish to test: ";
    std::cin >> k;

    std::cout << "  The sum " << k << ' ';

    if (CheckForSum(k,l))
        std::cout << "exists.\n";
    else
        std::cout << "does not exist.\n";
    
    return 0;
}

bool CheckForSum(int k, std::list<int> &l)
{
    for (std::list<int>::iterator i = l.begin(); i != l.end(); ++i)
    {
        std::list<int>::iterator j = i;
        while(j != l.end())
        {
            if (k == *++j + *i)
                return true;
        }
    }
    return false;
}
