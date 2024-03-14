#include "cdata.h"
#include <iostream>

int* expand_cdata(const cdata a[], int n) {
    // Calculate total size needed for the expanded array
    int totalSize = 0;
    for (int i = 0; i < n; ++i) {
        totalSize += a[i].count;
    }

    // Dynamically allocate memory for the expanded array
    int* expandedArray = new int[totalSize];

    // Fill the expanded array with values from cdata elements
    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < a[i].count; ++j) {
            expandedArray[index++] = a[i].value;
        }
    }

    return expandedArray;
}

int main() {
    // Test cases
    const int n1 = 1;
    const cdata a1[] = { { 3, 999 } };
    int* r1 = expand_cdata(a1, n1);
    print_array(r1, 3);
    delete [] r1;

    const int n2 = 3;
    const cdata a2[] = { { 3, 100 }, { 2, 200 }, { 1, 300 } };
    int* r2 = expand_cdata(a2, n2);
    print_array(r2, 6);
    delete [] r2;

    const int n3 = 1;
    const cdata a3[] = { { 1, 999 } };
    int* r3 = expand_cdata(a3, n3);
    print_array(r3, 1);
    delete [] r3;

    const int n4 = 2;
    const cdata a4[] = { { 20, 1 }, { 17, 2} };
    int* r4 = expand_cdata(a4, n4);
    print_array(r4, 37);
    delete [] r4;

    const int n5 = 4;
    const cdata a5[] = { { 2, 5 }, { 1, 2 }, { 3, 0 }, { 7, -1 } };
    int* r5 = expand_cdata(a5, n5);
    print_array(r5, 13);
    delete [] r5;

    return 0;
}
