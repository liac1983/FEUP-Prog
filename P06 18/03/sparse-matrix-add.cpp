#include <iostream>
#include <vector>
#include "smatrix.h"

void sum(const smatrix& a, const smatrix& b, smatrix& r) {
    // Clear the result matrix r
    r.clear();
    
    // Indices to iterate over matrices a and b
    size_t idxA = 0, idxB = 0;
    
    // Iterate until we reach the end of either a or b
    while (idxA < a.size() && idxB < b.size()) {
        // Compare the indices (row and column) of the current entries in a and b
        if (a[idxA].row < b[idxB].row || (a[idxA].row == b[idxB].row && a[idxA].col < b[idxB].col)) {
            // If the current entry in a comes before the current entry in b, add it to r
            r.push_back(a[idxA]);
            idxA++;
        } else if (a[idxA].row > b[idxB].row || (a[idxA].row == b[idxB].row && a[idxA].col > b[idxB].col)) {
            // If the current entry in b comes before the current entry in a, add it to r
            r.push_back(b[idxB]);
            idxB++;
        } else {
            // If the current entries in a and b have the same indices, sum their values
            int sumValue = a[idxA].value + b[idxB].value;
            // If the sum is non-zero, add it to r
            if (sumValue != 0) {
                r.push_back({a[idxA].row, a[idxA].col, sumValue});
            }
            // Move to the next entries in both a and b
            idxA++;
            idxB++;
        }
    }
    
    // Add any remaining entries from a, if there are any
    while (idxA < a.size()) {
        r.push_back(a[idxA]);
        idxA++;
    }
    
    // Add any remaining entries from b, if there are any
    while (idxB < b.size()) {
        r.push_back(b[idxB]);
        idxB++;
    }
}

int main() {
    // Test cases
    smatrix r;
    sum({ },
        { {0, 3, 1}, {0, 50, 1} },
        r);
    print(r);

    r.clear();
    sum({ {0, 0, 1}, {1, 0, 1} },
        { {0, 3, 1}, {0, 50, 1} },
        r);
    print(r);

    r.clear();
    sum({ {0, 0, 1}, {0, 1, 2}, {5, 10, 20}, {99, 12, 32} },
        { {0, 0, 1}, {0, 1, -2}, {10, 5, 20}, {99, 10, 30}, {99, 11, 31} },
        r);
    print(r);

    r.clear();
    sum({ {0, 0, -1}, {0, 1, 2}, {5, 10, 20}, {10, 5, -20} },
        { {0, 0, 1}, {0, 1, -2}, {10, 5, 20} },
        r);
    print(r);

    r.clear();
    sum({ {0, 0, -1}, {0, 1, 2},  {5, 10, 20 }, {10, 5, -20} },
        { {0, 0, 1}, {0, 1, -2},  {5, 10, -20}, {10, 5, 20} },
        r);
    print(r);

    return 0;
}
