#include "interval.h"
#include <iostream>

using namespace std;

bool operator<(const time_of_day& a, const time_of_day& b) {
    return (a.h < b.h) || (a.h == b.h && a.m < b.m);
}

interval intersection(interval a, interval b) {
    interval result;

    // Check if there is an intersection
    if (b.start < a.end && a.start < b.end) {
        // Calculate the start time of the intersection
        if (a.start < b.start) {
            result.start = b.start;
        } else {
            result.start = a.start;
        }

        // Calculate the end time of the intersection
        if (a.end < b.end) {
            result.end = a.end;
        } else {
            result.end = b.end;
        }
    } else {
        // No intersection, set both start and end to {0, 0}
        result.start = {0, 0};
        result.end = {0, 0};
    }

    return result;
}


int main() {
    std::cout << intersection( { { 12, 30 }, { 14, 30 } }, { { 17, 30 }, { 18, 30 } } ) << '\n';
    std::cout << intersection( { { 12, 30 }, { 14, 30 } }, { { 14, 30 }, { 18, 30 } } ) << '\n';
    std::cout << intersection( { { 12, 30 }, { 14, 31 } }, { { 14, 30 }, { 18, 30 } } ) << '\n';
    std::cout << intersection( { { 14, 30 }, { 15, 59 } }, { { 11, 30 }, { 14, 31 } } ) << '\n';
    std::cout << intersection( { {  4, 30 }, {  7, 59 } }, { {  4,  0 }, {  7, 29 } } ) << '\n';
    std::cout << intersection( { { 23,  0 }, { 23, 58 } }, { { 22, 45 }, { 23, 59 } } ) << '\n';
    std::cout << intersection( { { 17,  0 }, { 19,  0 } }, { { 15,  0 }, { 17,  0 } } ) << '\n';

    return 0;
}