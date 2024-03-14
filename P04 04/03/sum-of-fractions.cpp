#include "fraction.h"

// Function to compute the greatest common divisor using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute the least common multiple
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Function to compute the sum of fractions
fraction sum(const fraction fa[], int n) {
    // Initialize the sum fraction
    fraction result = {0, 1};

    // Iterate through the fractions and accumulate the sum
    for (int i = 0; i < n; ++i) {
        // Compute the least common multiple of the denominators
        int common_denominator = lcm(result.den, fa[i].den);

        // Adjust the numerators according to the common denominator
        int numerator1 = result.num * (common_denominator / result.den);
        int numerator2 = fa[i].num * (common_denominator / fa[i].den);

        // Add the numerators and update the result
        result.num = numerator1 + numerator2;
        result.den = common_denominator;

        // Simplify the fraction
        int common_divisor = gcd(result.num, result.den);
        result.num /= common_divisor;
        result.den /= common_divisor;
    }

    return result;
}

int main() {
    const int n = 1;
    const fraction fa1[n] = { {1, 2} };
    cout << sum(fa1, n) << '\n';

    const int n2 = 2;
    const fraction fa2[n2] = { {1, 2}, {-1, 3} };
    cout << sum(fa2, n2) << '\n';

    const int n3 = 3;
    const fraction fa3[n3] = { {1, 2}, {-1, 3}, {-3, 4} };
    cout << sum(fa3, n3) << '\n';

    const int n4 = 4;
    const fraction fa4[n4] = { {-1, 4}, {1, 2}, {-1, 8}, {-1, 8} };
    cout << sum(fa4, n4) << '\n';

    const int n5 = 5;
    const fraction fa5[n5] = { {0, 1}, {1, 2}, {-2, 3}, {3, 4}, {-4, 5} };
    cout << sum(fa5, n5) << '\n';

    const int n6 = 6;
    const fraction fa6[n6] = { {133,60}, {0, 1}, {1, 2}, {-2, 3}, {3, 4}, {-4, 5} };
    cout << sum(fa6, n6) << '\n';

    return 0;
}
