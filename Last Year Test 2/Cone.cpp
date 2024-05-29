#include "Solid3D.h"

class Cone : public Solid3D {
public:
  Cone(const point& c, double r, double h) 
     : Solid3D(c), radius_(r), height_(h) {}
  double radius() const {
    return radius_;
  }
  double height() const {
    return height_;
  }
  double volume() const override {
    return (M_PI * radius_ * radius_ * height_) / 3;
  }

private:
  double radius_;
  double height_;
};

#include <iostream>
using namespace std;

int main()
{
  // public tests (1 point each)
  {
    const Cone c({0, 0, 0}, 1, 1);
    cout << c.center() << ' ' 
         << c.radius() << ' ' 
         << c.height() << ' ' 
         << c.volume() << endl;
  } // -> (0.000,0.000,0.000) 1.000 1.000 1.047
  {
    const Cone c({0.1, 2.3, 4.5}, 1.2, 3.4);
    cout << c.center() << ' ' 
         << c.radius() << ' ' 
         << c.height() << ' ' 
         << c.volume() << endl;
  } // -> (0.100,2.300,4.500) 1.200 3.400 5.127
  {
    const Solid3D& s = Cone({-1.2, -3.4, -5.6}, 1.2, 0.34);
    cout << s.center() << ' ' << s.volume() << endl;
  } // -> (-1.200,-3.400,-5.600) 0.513
  {
    const Solid3D& s = Cone({12.3, 34.5, 56.7}, 12.3, 0.51);
    cout << s.center() << ' ' << s.volume() << endl;
  } // -> (12.300,34.500,56.700) 80.800
  cout << endl;
  // private tests (1000 points each)
  {
    const Cone c({3.2, 1.1, 1.3}, 1, 1);
    cout << c.center() << ' ' 
         << c.radius() << ' ' 
         << c.height() << ' ' 
         << c.volume() << endl;
  } // -> (3.200,1.100,1.300) 1.000 1.000 1.047
  {
    const Cone c({0.1, 2.3, 4.5}, 3.4, 1.2);
    cout << c.center() << ' ' 
         << c.radius() << ' ' 
         << c.height() << ' ' 
         << c.volume() << endl;
  } // -> (0.100,2.300,4.500) 3.400 1.200 14.527
  {
    const Solid3D& s = Cone({-12, -34, -56}, 0.11, 0.45);
    cout << s.center() << ' ' << s.volume() << endl;
  } // -> (-12.000,-34.000,-56.000) 0.006
  {
    const Solid3D& s = Cone({123, 345, 567}, 1.23, 45.1);
    cout << s.center() << ' ' << s.volume() << endl;
  } // -> (123.000,345.000,567.000) 71.452
 
  return 0;
}