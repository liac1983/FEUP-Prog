// Polygon.h
#ifndef POLYGON_H
#define POLYGON_H

#include "Point.h"
#include <vector>

class Polygon {
public:
    Polygon(); // default constructor
    Polygon(const std::vector<Point>& vertices); // parameterized constructor

    // Accessors
    int total_number_of_vertices() const;
    bool get_vertex(int vertex_number, Point& p) const;
    double perimeter() const;

    // Mutators
    void add_vertex(int position, const Point& p);

    // Other member functions
    void show() const;

private:
    std::vector<Point> vertices_;
};

#endif // POLYGON_H
