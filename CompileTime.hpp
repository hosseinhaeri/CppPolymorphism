#include <iostream>
#include <chrono>
#include <string>

namespace compile_time
{

using std::cout;
using std::endl;
using std::string;

//Compile-Time Computation******************************************************************
template<unsigned long long N>
struct fact
{
  constexpr static unsigned long long value = N * fact<N - 1>::value;
};

template<>
struct fact<0>
{
  constexpr static unsigned long long value = 1;
};
//Zero-Overhead Demo************************************************************************
void demo_fact()
{
  using namespace std::chrono;

  auto t1b = high_resolution_clock::now();
  constexpr auto f1 = fact<1>::value;
  auto t1e = high_resolution_clock::now();
  auto d1 = duration_cast<microseconds>(t1b - t1e);

  auto t25b = high_resolution_clock::now();
  constexpr auto f25 = fact<25>::value;
  auto t25e = high_resolution_clock::now();
  auto d25 = duration_cast<microseconds>(t25b - t25e);  
  
  cout << "Computing fact(1) = "  << f1  << " took " << d1.count()  << " microseconds." << endl;
  cout << "Computing fact(25) = " << f25 << " took " << d25.count() << " microseconds." << endl;
}
//The Pair Data Structure*******************************************************************
template<typename T1, typename T2>
struct Pair
{
  T1 first_;
  T2 second_;
};

template<typename T1, typename T2> Pair(T1, T2) -> Pair<T1, T2>;

auto p1 = Pair{44, string("test")};//pair of int and string
auto p2 = Pair{p1, 3.14};//pair of "pair of int and string" and double

//How miserable could have life been if we had to do the following?
struct PIntString
{
  PIntString(int i, string s): first_(i), second_(s) {}

  int first_;
  string second_;
};

struct PIntStringDouble
{
  PIntStringDouble(PIntString p, double d): first_(p), second_(d) {}

  PIntString first_;
  double second_;
};

auto q1 = PIntString(44, string("test"));
auto q2 = PIntStringDouble(q1, 3.14);

}//namespace compile_time