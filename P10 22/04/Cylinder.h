#ifndef CYLINDER_H
#define CYLINDER_H

#include "Solid.h"
#include <cmath>
#include <iostream>

class Cylinder : public Solid {
public:
  // Constructor that takes a cylinder's center, radius, and height
  Cylinder(const point& c, double r, double h) : Solid(c), radius_(r), height_(h) {}

  // Method to obtain a cylinder's radius
  double radius() const { return radius_; }

  // Method to obtain a cylinder's height
  double height() const { return height_; }

  // Override the area() function to calculate the surface area of the cylinder
  double area() const override {
    return 2 * M_PI * radius_ * (radius_ + height_);
  }

private:
  double radius_; // Cylinder's radius
  double height_; // Cylinder's height
};

#endif // CYLINDER_H
