#include "fraction.h"
#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

fraction reduce(fraction f) {
    int divisor = gcd(std::abs(f.num), f.den);
    f.num /= divisor;
    f.den /= divisor;
    if (f.den < 0) {
        f.num = -f.num;
        f.den = -f.den;
    }
    return f;
}

fraction add(fraction a, fraction b) {
    fraction result;
    result.num = a.num * b.den + b.num * a.den;
    result.den = a.den * b.den;
    return reduce(result);
}

fraction mul(fraction a, fraction b) {
    fraction result;
    result.num = a.num * b.num;
    result.den = a.den * b.den;
    return reduce(result);
}

int main() {
    std::cout << add({ 0, 1 }, { 2, 1 }) << ' ' << mul({ 0, 1 }, { 2, 1 }) << '\n';
    std::cout << add({ 1, 1 }, { -1, 2 }) << ' ' << mul({ 1, 1 }, { -1, 2 }) << '\n';
    std::cout << add({ -3, 2 }, { 3, 2 }) << ' ' << mul({ -3, 2 }, { 3, 2 }) << '\n';
    std::cout << add({ -3, 2 }, { -2, 3 }) << ' ' << mul({ -3, 2 }, { -2, 3 }) << '\n';
    std::cout << add({ -7, 24 }, { 1, 3 }) << ' ' << mul({ -7, 24 }, { 1, 3 }) << '\n';
    std::cout << add({ -8, 25 }, { 3, 4 }) << ' ' << mul({ -8, 25 }, { 3, 4 }) << '\n';
    std::cout << add({7,4536}, mul({-5,21}, add({1,2}, mul({-2,3}, {1,9})))) << '\n';

    return 0;
}