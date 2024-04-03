#include <iostream>
#include <vector>
#include <algorithm>
#include "print_vector.h"

template <typename T>
void normalise(std::vector<T>& v, const T& min, const T& max) {
    for (T& x : v) {
        if (x < min) {
            x = min;
        } else if (x > max) {
            x = max;
        }
        // Otherwise, leave x unchanged
    }
}

int main() {
    // Test cases
    std::vector<int> v1 { };
    normalise(v1, 0, 1);
    print(v1);

    std::vector<int> v2 { 1, 2, 3, 4, 5 };
    normalise(v2, 1, 5);
    print(v2);

    std::vector<int> v3 { 1, 2, 3, 4, 5 };
    normalise(v3, 3, 4);
    print(v3);

    std::vector<double> v4 { -1.2, 2.2, -3.5, 4.3, 5.2 };
    normalise(v4, 0.5, 5.1);
    print(v4);

    std::vector<std::string> v5 { "Diego", "Afonso", "Antonio", "Bernardo", "Tolentino", "Zeferino", "Xavier" };
    normalise(v5, std::string("Antonio"), std::string("Zacarias"));
    print(v5);

    return 0;
}
