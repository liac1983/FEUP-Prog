#include "Point2d.h"
#include <cmath>
#include <iostream> // For sqrt function
#include <iomanip> 

using namespace std;

void Point2d::translate(const Point2d& t) {
    x += t.get_x();
    y += t.get_y();
}

double Point2d::distance_to(const Point2d& p) const {
    double dx = x - p.get_x();
    double dy = y - p.get_y();
    return sqrt(dx * dx + dy * dy);
}

int main() {
    { Point2d a { 1.0, 2.1 };
  a.translate({ -0.3, 0.5 });
  cout << fixed << setprecision(2) 
       << a.get_x() << ' ' << a.get_y() << '\n'; }
    
    { Point2d a { 1.0, 2.1 }, b { 2.0, 3.1 };
  cout << fixed << setprecision(2) 
       << a.distance_to(b) << '\n'; }
    
    { Point2d a { 0, 0 }; Point2d b = a;
  a.translate({ 0, 0 });
  cout << fixed << setprecision(2) 
       << a.get_x() << ' ' << a.get_y() << ' '
       << a.distance_to(b) << '\n'; }
    
    { Point2d a { 0, 1 }; Point2d b = a;
  a.translate({ 1.5, 0 });
  cout << fixed << setprecision(2) 
       << a.get_x() << ' ' << a.get_y() << ' '
       << a.distance_to(b) << '\n'; }
    
    { Point2d a { 1, 0 }; Point2d b = a;
  a.translate({ -1, 2.5 });
  cout << fixed << setprecision(2) 
       << a.get_x() << ' ' << a.get_y() << ' '
       << a.distance_to(b) << '\n'; }

    return 0;
}
