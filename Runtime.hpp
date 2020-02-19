#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

namespace runtime
{

class Shape
{
public:
  virtual void prompt() const = 0;
};
//------------------------------------------------------------------------------------------
class Circle: public Shape
{
public:
  Circle(double d): d_(d) {}

  virtual void prompt() const override
  {
    cout << "Circle of diameter " << d_ << "." << endl;
  }
private:
  double d_;
};
//------------------------------------------------------------------------------------------
class Smiley: public Circle
{
public:
  Smiley(string face): Circle(1.0), face_(face) {}

  virtual void prompt() const override
  {
    cout << "Smiley of " << face_ << " face." << endl; 
  }
private:
  string face_;
};
//------------------------------------------------------------------------------------------
class Triangle: public Shape
{
public:
  Triangle(double b, double h): base_(b), hight_(h) {}

  virtual void prompt() const override
  {
    cout << "Triangle of base " << base_ << " and hight " << hight_ << "." << endl;
  }
private:
  double base_, hight_;
};

void test()
{
  Shape* shapes[] = {new Circle(5.6), new Smiley("happy"), new Triangle(12.0, 14.0)};

  for(auto sp: shapes)
    sp->prompt();
}

}//namespace runtime