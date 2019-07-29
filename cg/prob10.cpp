/*
  Problem 10 : MEDIUM

  Implement a job scheduler which takes in a function f and an integer n, and
  calls f after n milliseconds.

  Chris Georgiades
*/

#include <iostream>
#include <unistd.h> // needed for sleep()
#include <time.h>

void F();
void prob10(int&, void (*F)());

int main()
{
  int n; 
  std::cout << "How long till you call F() in s? ";
  std::cin >> n;

  time_t start = time(NULL); 
  prob10(n,F);
  time_t finish = time(NULL);
  int total = finish - start;
  std::cout << "Total time taken is " << total << " seconds\n";

  return 0;
}

void F()
{
  std::cout << "Calling function F()\n";
}

void prob10(int& n, void (*F)())
{
  sleep(n);
  F();
}
