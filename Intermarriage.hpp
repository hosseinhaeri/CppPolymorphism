#include <iostream>

#include "Runtime.hpp"
#include "CompileTime.hpp"

namespace inter_marriage
{
using std::cout;
using std::endl;

using namespace runtime;
using namespace compile_time;

//Child 1: Runtime Out**********************************************************************
template<typename T>
struct Base
{
  virtual void virt_f() const
  {
    cout << "This is Base<T>'s virtual function." << endl;
  }
  void f() const
  {
    cout << "This is Base<T>'s non-virtual function." << endl;
  }
};

template<typename T>
struct Derived: public Base<T>
{
  virtual void virt_f() const override
  {
    cout << "This is Derived<T>'s virtual function." << endl;
  }
  void f() const
  {
    cout << "This is Derived<T>'s non-virtual function." << endl;
  }
};
//-----------------------------------------------------------------------------------------
void demo_children()
{
  cout << "Demonstrating child 1 (Runtime Out)..." << endl;
  Base<int>* bp = new Derived<int>;
  bp->virt_f();
  bp->f();

  //Child 2: Compile-Time Out
  auto p = Pair{bp, bp};
  cout << "Now child 2 (Compile-Time Out)..." << endl
       << "On p.first_: " << endl;
  p.first_->virt_f();
  cout << "On p.second_: " << endl;
  p.second_->virt_f();

  delete bp;
}

}//namespace inter_marriage