#include <iostream>

unsigned long bc(unsigned long n, unsigned long k) {
    // If k is greater than n-k, compute n choose n-k instead to minimize calculations
    if (k > n - k) {
        k = n - k;
    }

    // Initialize result to 1
    unsigned long result = 1;

    // Calculate binomial coefficient using the formula: (n choose k) = n! / (k! * (n - k)!)
    for (unsigned long i = 0; i < k; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }

    return result;
}

int main() {
    std::cout << bc(5, 0) << '\n';
    std::cout << bc(5, 1) << '\n';
    std::cout << bc(5, 5) << '\n';
    std::cout << bc(5, 2) << '\n';
    std::cout << bc(12, 7) << '\n';
    std::cout << bc(20, 10) << '\n';

    return 0;
}
