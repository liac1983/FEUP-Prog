#include <iostream>

using namespace std;

int adigits(int a, int b, int c) {
    int max_digit = a > b ? (a > c ? a : c) : (b > c ? b : c); // Find the maximum digit
    int min_digit = a < b ? (a < c ? a : c) : (b < c ? b : c); // Find the minimum digit
    int mid_digit = (a + b + c) - (max_digit + min_digit); // Find the middle digit

    return max_digit * 100 + mid_digit * 10 + min_digit; // Assemble the highest number
}

int main() {
    std::cout << adigits(4, 2, 5) << '\n';
    std::cout << adigits(9, 1, 9) << '\n';
    std::cout << adigits(1, 2, 3) << '\n';
    std::cout << adigits(1, 0, 0) << '\n';
    return 0;
}
