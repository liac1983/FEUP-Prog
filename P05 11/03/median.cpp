#include <iostream>
#include <algorithm> // for std::sort

int median(const int a[], int n) {
    // Create a temporary array and copy values from 'a' to it
    int* tmp = new int[n];
    std::copy(a, a + n, tmp);

    // Sort the temporary array
    std::sort(tmp, tmp + n);

    // Compute the median value
    int medianValue;
    if (n % 2 == 1) {
        medianValue = tmp[n / 2];
    } else {
        medianValue = (tmp[n / 2 - 1] + tmp[n / 2]) / 2;
    }

    // Release the memory associated with tmp
    delete[] tmp;

    return medianValue;
}

int main() {
    // Test cases
    const int n1 = 5;
    int a1[n1] = { 10, -10, 0, 12, 11 };
    std::cout << median(a1, n1) << '\n';

    const int n2 = 6;
    int a2[n2] = { 30, 10, 0, -20, 14, 20 };
    std::cout << median(a2, n2) << '\n';

    const int n3 = 1;
    int a3[n3] = { 99 };
    std::cout << median(a3, n3) << '\n';

    const int n4 = 2;
    int a4[n4] = { 101, 99 };
    std::cout << median(a4, n4) << '\n';

    return 0;
}
