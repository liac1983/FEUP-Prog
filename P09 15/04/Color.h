// Color.h

#ifndef COLOR_H
#define COLOR_H

class Color {
public:
    // Constructor
    Color(unsigned char red, unsigned char green, unsigned char blue);

    // Copy constructor
    Color(const Color& c);

    // Accessors
    unsigned char red() const;
    unsigned char green() const;
    unsigned char blue() const;

    // Static class constants
    static const Color RED;
    static const Color GREEN;
    static const Color BLUE;
    static const Color BLACK;
    static const Color WHITE;

    // Member function to test equality between colors
    bool equal_to(const Color& other) const;

    // Member function to invert a color
    void invert();

private:
    unsigned char _red;
    unsigned char _green;
    unsigned char _blue;
};

#endif // COLOR_H
