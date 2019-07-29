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
  std::cout << "How long till you call F() in ms? ";
  std::cin >> n;
  n /= 1000;
  time_t start = time(0); 
  prob10(n,F); // call routine to invoke F() aftern ms
  time_t finish = time(0);
  float total = (finish - start)*1000; // adjust for milli
  std::cout << "Total time taken = " << total << "ms\n";

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
