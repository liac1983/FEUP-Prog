#include "complex.h"
#include <iostream>

using namespace std;

void add(const complex& a, const complex& b, complex& r) {
    r.x = a.x + b.x;
    r.y = a.y + b.y;
}

void mul(const complex& a, const complex& b, complex& r) {
    r.x = a.x * b.x - a.y * b.y;
    r.y = a.x * b.y + a.y * b.x;
}

void mandelbrot(const complex& c, unsigned int n, complex& z_n) {
    z_n = {0, 0}; // Initialize z_n to 0+0i
    for (unsigned int i = 1; i <= n; ++i) {
        complex z_prev = z_n;
        mul(z_prev, z_prev, z_n); // z_n = z_{n-1} * z_{n-1}
        add(z_n, c, z_n);         // z_n = z_n + c
    }
}


int main() {
    complex z_n;
    mandelbrot({1.2, 3.4}, 0, z_n);
    std::cout << z_n << '\n';

    mandelbrot({1, 1}, 1, z_n);
    std::cout << z_n << '\n';

    mandelbrot({1, 1}, 2, z_n);
    std::cout << z_n << '\n';

    mandelbrot({-1.2, 0.4}, 7, z_n);
    std::cout << z_n << '\n';

    mandelbrot({0.1, 3.2}, 4, z_n);
    std::cout << z_n << '\n';

    mandelbrot({-1, 0}, 11, z_n);
    std::cout << z_n << '\n';

    return 0;
}