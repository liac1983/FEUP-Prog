// Point.h
#ifndef POINT_H
#define POINT_H

class Point {
public:
    Point(); // default constructor
    Point(int x, int y); // parameterized constructor

    // Accessors
    int get_x() const;
    int get_y() const;

    // Mutators
    void set_x(int x);
    void set_y(int y);

    // Other member functions
    void show() const;

private:
    int x_;
    int y_;
};

#endif // POINT_H
