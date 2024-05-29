#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <cmath>

class Circle : public Shape {
public:
  // Constructor that takes center point and radius
  Circle(const point& center, double radius) : Shape(center), radius_(radius) {}

  // Accessor function for radius
  double radius() const { return radius_; }

  // Override area() function to calculate area of circle
  double area() const override {
    return M_PI * radius_ * radius_;
  }

  // Override perimeter() function to calculate perimeter of circle
  double perimeter() const override {
    return 2 * M_PI * radius_;
  }

  // Override contains() function to determine if a point is inside the circle
  bool contains(const point& p) const override {
    double dx = get_center().x - p.x;
    double dy = get_center().y - p.y;
    double distance = sqrt(dx * dx + dy * dy);
    return distance <= radius_;
  }

private:
  double radius_; // Radius of the circle
};

#endif // CIRCLE_H
