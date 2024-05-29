#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
public:
  // Constructor that takes center point, width, and height
  Rectangle(const point& center, double width, double height)
    : Shape(center), width_(width), height_(height) {}

  // Accessor functions for width and height
  double width() const { return width_; }
  double height() const { return height_; }

  // Override area() function to calculate area of rectangle
  double area() const override {
    return width_ * height_;
  }

  // Override perimeter() function to calculate perimeter of rectangle
  double perimeter() const override {
    return 2 * (width_ + height_);
  }

  // Override contains() function to determine if a point is inside the rectangle
  bool contains(const point& p) const override {
    return (p.x >= get_center().x - width_ / 2) && (p.x <= get_center().x + width_ / 2) &&
           (p.y >= get_center().y - height_ / 2) && (p.y <= get_center().y + height_ / 2);
  }

private:
  double width_;  // Width of the rectangle
  double height_; // Height of the rectangle
};

#endif // RECTANGLE_H
