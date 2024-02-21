#include <iostream>

unsigned long pell(unsigned long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    unsigned long p_prev = 0; // P0
    unsigned long p_curr = 1; // P1

    for (unsigned long i = 2; i <= n; ++i) {
        unsigned long p_next = 2 * p_curr + p_prev; // Pn = 2 * Pn-1 + Pn-2
        p_prev = p_curr;
        p_curr = p_next;
    }

    return p_curr;
}

int main() {
    std::cout << pell(0) << '\n';
    std::cout << pell(1) << '\n';
    std::cout << pell(2) << '\n';
    std::cout << pell(3) << '\n';
    std::cout << pell(5) << '\n';
    std::cout << pell(50) << '\n';

    return 0;
}
