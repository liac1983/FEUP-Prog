#include "complex.h"
#include <iostream>
#include <cmath>

using namespace std;

void add(const complex& a, const complex& b, complex& r) {
    r.x = a.x + b.x;
    r.y = a.y + b.y;
}

void mul(const complex& a, const complex& b, complex& r) {
    r.x = a.x * b.x - a.y * b.y;
    r.y = a.x * b.y + a.y * b.x;
}

double norm(const complex& c) {
    return sqrt(c.x * c.x + c.y * c.y);
}

int main() {
    complex a = {0, 1}, b = {2, 1}, s, m;
    add(a, b, s);
    mul(a, b, m);
    std::cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n';

    a = {1.2, 3.4}, b = {-1.2, 2.3};
    add(a, b, s);
    mul(a, b, m);
    std::cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n';

    a = {-1.5, 1}, b = {-1, 2};
    add(a, b, s);
    mul(a, b, m);
    std::cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n';

    a = {-2, 2}, b = {2, -2};
    add(a, b, s);
    mul(a, b, m);
    std::cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n';

    a = {0, 0}, b = {1.2, -3.4};
    add(a, b, s);
    mul(a, b, m);
    std::cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n';

    a = {2, 0}, b = {2.5, -3.1};
    add(a, b, s);
    mul(a, b, m);
    std::cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n';

    return 0;
}
