/*
Problem #4
Difficulty: HARD

Given an array of integers, find the first missing positive integer in linear time and constant space. 
In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.
For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.
You can modify the input array in-place.

Chris Georgiades
04.26.19
*/

#include <iostream>
#include <list>

int prob4(int*, std::list<int>&, size_t&);

int main()
{
  int* srcPtr;
  size_t aSize;
  std::list<int> list;

  std::cout << "Enter the size of the array: ";
  std::cin >> aSize;
  std::cout << "Enter " << aSize << " integers:\n";

  int src[aSize];
  srcPtr = &src[0];
  
  for (size_t i = 0; i < aSize; ++i)
    std::cin >> src[i];
  
  std::cout << "The lowest positive integer not in the array is: " << prob4(srcPtr, list, aSize) << std::endl;
  return 0;
}

int prob4(int* src, std::list<int>& l, size_t& aSize)
{
  size_t count = 0;
  int result = 1;
  
  while (count < aSize)
  {
    if (*src > 0)
      l.push_back(*src);
    ++src;
    ++count;
  }

  l.sort();

  for (std::list<int>::iterator i = l.begin(); i != l.end(); ++i)
  {
    if (*i > result)
      return result;
    else
      ++result;
  }
  return result;
}
