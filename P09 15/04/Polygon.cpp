// Polygon.cpp
#include "Polygon.h"
#include <iostream>
#include <cmath>

Polygon::Polygon() {}

Polygon::Polygon(const std::vector<Point>& vertices) : vertices_(vertices) {}

int Polygon::total_number_of_vertices() const {
    return vertices_.size();
}

bool Polygon::get_vertex(int vertex_number, Point& p) const {
    size_t num_vertices = vertices_.size(); // Use size_t for unsigned integer type
    if (vertex_number >= 1 && static_cast<size_t>(vertex_number) <= num_vertices) { // Cast to size_t
        p = vertices_[vertex_number - 1];
        return true;
    } else {
        return false;
    }
}

double Polygon::perimeter() const {
    double perimeter = 0.0;
    size_t num_vertices = vertices_.size(); // Use size_t for unsigned integer type
    if (num_vertices < 2) return perimeter;

    for (size_t i = 0; i < num_vertices; ++i) { // Use size_t for loop variable
        size_t next_index = (i + 1) % num_vertices; // next vertex index
        double dx = vertices_[next_index].get_x() - vertices_[i].get_x();
        double dy = vertices_[next_index].get_y() - vertices_[i].get_y();
        perimeter += std::sqrt(dx * dx + dy * dy);
    }

    return perimeter;
}

void Polygon::add_vertex(int position, const Point& p) {
    size_t num_vertices = vertices_.size(); // Use size_t for unsigned integer type
    if (position < 1 || static_cast<size_t>(position) > num_vertices + 1) { // Cast to size_t
        std::cerr << "Invalid position to add vertex\n";
        return;
    }

    vertices_.insert(vertices_.begin() + position - 1, p);
}

void Polygon::show() const {
    std::cout << "{";
    for (const Point& p : vertices_) {
        p.show();
    }
    std::cout << "}";
}
