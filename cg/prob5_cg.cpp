/*
  Problem 5
  Difficulty: MEDIUM

  cons(a, b) constructs a pair, and car(pair) and cdr(pair) 
  returns the first and last element of that pair. For example, 
  car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.
  
  Given this implementation of cons:

  def cons(a, b):
   def pair(f):
        return f(a, b)
    return pair
 
  Implement car and cdr.
 */

#include <iostream>

template <typename F, typename S>
class Pair;

template <typename F, typename S>
class Pair
{
public:
  typedef F First;
  typedef S Second;

  Pair();
  Pair(First, Second);

  // needed for private access
  First GetF();
  Second GetS();

private:
  First first_;
  Second second_;
};

// comment out unwanted types
//typedef int F;
//typedef int S;
typedef std::string F;
typedef std::string S;

// challenge methods
F car(Pair<F, S>&);
S cdr(Pair<F,S>&);

int main()
{
  F a;
  S b;

  std::cout << "Enter pair value 1 and 2 respectively:\n";
  std::cin >> a >> b;

  Pair<F, S> p(a,b);

  std::cout
    << "car: " << car(p) << '\n'
    << "cdr: " << cdr(p) << std::endl;

  return 0;
}

template <typename F, typename S>
Pair<F, S>::Pair()
{
  first_ =  NULL;
  second_ = NULL;
}

template <typename F, typename S>
Pair<F,S>::Pair(First f, Second s) : first_(f), second_(s)
{} // parameterized constructor

template <typename F, typename S>
F Pair <F,S>::GetF()
{
  return this->first_;
}

template <typename F, typename S>
S Pair<F, S>::GetS()
{
  return this->second_;
}

F car(Pair<F, S>& p)
{
  return p.GetF();
}

S cdr(Pair<F, S>& p)
{
  return p.GetS();
}
