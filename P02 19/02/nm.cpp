#include <iostream>

unsigned long long next_mersenne(unsigned long long n) {
    // Special cases
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    // Start with n
    unsigned long long mersenne = n;

    // Loop until we find the next Mersenne number
    while (true) {
        // Check if the current number is a Mersenne number
        unsigned long long exponent = 0;
        unsigned long long m = mersenne + 1;
        while ((m & 1) == 0) {
            m >>= 1;
            exponent++;
        }
        if (m == 1)
            return mersenne;

        // Update to the next number
        mersenne += 1ULL << exponent;
    }
}

int main() {
    std::cout << next_mersenne(0) << '\n';
    std::cout << next_mersenne(1) << '\n';
    std::cout << next_mersenne(2) << '\n';
    std::cout << next_mersenne(4) << '\n';
    std::cout << next_mersenne(128) << '\n';
    std::cout << next_mersenne(4294967296ULL) << '\n';

    return 0;
}
