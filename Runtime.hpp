#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::cin;

namespace runtime
{

//The Hierarchy*****************************************************************************
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
//The Demo**********************************************************************************
void demo()
{
  vector<Shape*> shapes;
  
  unsigned choice = 1;
  while(choice != 0)
  {
    cout << "(0) Exit, (1) Circle, (2) Smiley, or (3) Triangle? ";
    cin >> choice;
    if(choice == 1)
      shapes.push_back(new Circle(5.6));
    else if(choice == 2)
      shapes.push_back(new Smiley("happy"));
    else if(choice == 3)
      shapes.push_back(new Triangle(12.0, 14.0));
  }

  for(auto sp: shapes)
    sp->prompt();

  //If we didn't have the virtual dispatch, we had to do this manually.
  //Thing about extending it, and, it's a nightmare!
  // for(auto sp: shapes)
  // {
  //   if(auto cp = dynamic_cast<Circle*>(sp))
  //     cp->prompt();
  //   else if(auto smp = dynamic_cast<Smiley*>(sp))
  //     smp->prompt();
  //   else if(auto tp = dynamic_cast<Triangle*>(sp))
  //     tp->prompt();
  // }
}

}//namespace runtime