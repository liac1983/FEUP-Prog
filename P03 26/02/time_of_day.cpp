#include "time_of_day.h"
#include <iostream>

using namespace std;

time_of_day tick(time_of_day t) {
    // Increment minutes
    t.m++;

    // Handle overflow in minutes
    if (t.m >= 60) {
        t.m = 0;
        t.h++;
    }

    // Handle overflow in hours
    if (t.h >= 24) {
        t.h = 0;
    }

    return t;
}

int main() {
    std::cout << tick({ 0, 0 }) << '\n';
    std::cout << tick({ 12, 30 }) << '\n';
    std::cout << tick({ 12, 59 }) << '\n';
    std::cout << tick({ 23, 59 }) << '\n';
    std::cout << tick(tick(tick({ 23, 59 }))) << '\n';

    return 0;
}