// Color.cpp

#include "Color.h"

// Constructor
Color::Color(unsigned char red, unsigned char green, unsigned char blue)
    : _red(red), _green(green), _blue(blue) {}

// Copy constructor
Color::Color(const Color& c)
    : _red(c.red()), _green(c.green()), _blue(c.blue()) {}

// Accessors
unsigned char Color::red() const {
    return _red;
}

unsigned char Color::green() const {
    return _green;
}

unsigned char Color::blue() const {
    return _blue;
}

// Static class constants
const Color Color::RED(255, 0, 0);
const Color Color::GREEN(0, 255, 0);
const Color Color::BLUE(0, 0, 255);
const Color Color::BLACK(0, 0, 0);
const Color Color::WHITE(255, 255, 255);

// Member function to test equality between colors
bool Color::equal_to(const Color& other) const {
    return (_red == other.red()) && (_green == other.green()) && (_blue == other.blue());
}

// Member function to invert a color
void Color::invert() {
    _red = 255 - _red;
    _green = 255 - _green;
    _blue = 255 - _blue;
}
