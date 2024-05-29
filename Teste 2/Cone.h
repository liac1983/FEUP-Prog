#ifndef CONE_H
#define CONE_H

#include <cmath>
#include "Solid3D.h"

class Cone : public Solid3D {
public:
    // Constructor
    Cone(const point& c, double r, double h) : Solid3D(c), radius_(r), height_(h) { }

    // Accessor methods
    double radius() const { return radius_; }
    double height() const { return height_; }

    // Override the volume method
    double volume() const override {
        return (M_PI * radius_ * radius_ * height_) / 3.0;
    }

private:
    double radius_;
    double height_;
};

#endif // CONE_H
