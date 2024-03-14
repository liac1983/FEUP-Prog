#include <iostream>
#include "print_array.h" // Include the header file for print_array function

int filter_duplicates(const int a[], int n, int b[]) {
    int j = 0; // Index for array b
    b[j++] = a[0]; // Copy the first element from a to b

    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1]) { // Check if the current element is different from the previous one
            b[j++] = a[i]; // If yes, copy it to b
        }
    }

    return j; // Return the number of elements copied to array b
}

int main() {
    const int n = 12;
    const int a[n] = { 1, 2, 2, 3, 3, 3, 1, 1, 1, 2, 2, 3 };
    int b[n] = { 0 };
    int nf = filter_duplicates(a, n, b);
    print_array(b, nf); // Print the filtered array b

    return 0;
}
