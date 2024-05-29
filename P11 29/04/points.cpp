#include "Point.h"
#include <iostream>


Point::Point() : x_(0), y_(0) {}

Point::Point(int x, int y) : x_(x), y_(y) {}

Point::Point(const Point& p) : x_(p.x_), y_(p.y_) {}

int Point::get_x() const {
    return x_;
}

int Point::get_y() const {
    return y_;
}

Point& Point::operator=(const Point& p) {
    x_ = p.x_;
    y_ = p.y_;
    return *this;
}

Point Point::operator+(const Point& p) const {
    return Point(x_ + p.x_, y_ + p.y_);
}

Point& Point::operator+=(const Point& p) {
    x_ += p.x_;
    y_ += p.y_;
    return *this;
}

Point Point::operator*(int v) const {
    return Point(x_ * v, y_ * v);
}

Point operator*(int x, const Point& p) {
    return Point(x * p.get_x(), x * p.get_y());
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.get_x() << "," << p.get_y() << ")";
    return os;
}

int main() {
    // Test cases
    Point a, b(1, 2), c(b), d(3, 4);

    b = a;
    std::cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';

    Point a1, b1(1, 2), c1(b1), d1(3, 4);
    c1 = b1 = a1;
    std::cout << a1 << ' ' << b1 << ' ' << c1 << ' ' << d1 << '\n';

    Point a2(1, 2), b2(3, 4), c2 = a2 + b2, d2(5, 6);
    b2 += d2;
    std::cout << a2 << ' ' << b2 << ' ' << c2 << ' ' << d2 << '\n';

    Point a3(1, 2), b3(3, 4), c3 = a3 * 2, d3(5, 6);
    b3 = 2 * d3;
    std::cout << a3 << ' ' << b3 << ' ' << c3 << ' ' << d3 << '\n';

    Point a4(1, 1), b4(0, 1), c4(1, 0), d4(1, 1);
    d4 += c4 += b4 += a4 += Point(1, 2);
    d4 = 2 * d4 * 2;
    std::cout << a4 << ' ' << b4 << ' ' << c4 << ' ' << d4 << '\n';

    return 0;
}
