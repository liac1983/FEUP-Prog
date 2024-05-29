#ifndef FRECTANGLE_H
#define FRECTANGLE_H

#include "Figure.h"
#include <iostream>

class FRectangle : public Figure {
public:
  FRectangle(double x_center, double y_center, double width, double height)
    : Figure(x_center, y_center), width_(width), height_(height) {}

  void draw() const override {
    std::cout << "R(" << x_center_ << "," << y_center_ << ")(" << width_ << "," << height_ << ")";
  }

private:
  double width_;
  double height_;
};

#endif // FRECTANGLE_H
