#include "complex.h"

// Function to add two complex numbers
complex add(complex a, complex b) {
    complex result;
    result.real = a.real + b.real;
    result.img = a.img + b.img;
    return result;
}

// Function to multiply two complex numbers
complex multiply(complex a, complex b) {
    complex result;
    result.real = a.real * b.real - a.img * b.img;
    result.img = a.real * b.img + b.real * a.img;
    return result;
}


void mandel(complex c, int n, complex z[]) {
    z[0].real = 0;
    z[0].img = 0;

    for (int i = 1; i < n; ++i) {
        z[i] = add(multiply(z[i - 1], z[i - 1]), c);
    }
}

int main() {
    complex c = {0, 0};
    const int n = 1;
    complex z[n];
    mandel(c, n, z);
    print(z, n);

    c = {0, 0};
    const int n2 = 3;
    complex z2[n2];
    mandel(c, n2, z2);
    print(z2, n2);

    c = {1, 1};
    const int n3 = 3;
    complex z3[n3];
    mandel(c, n3, z3);
    print(z3, n3);

    c = {-1, 0};
    const int n4 = 6;
    complex z4[n4];
    mandel(c, n4, z4);
    print(z4, n4);

    c = {0, 3};
    const int n5 = 5;
    complex z5[n5];
    mandel(c, n5, z5);
    print(z5, n5);

    return 0;
}
