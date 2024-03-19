#include "print_array.h"

int filter_repeated(const int arr[], int size, int out[]) {
    int count = 0;

    // Iterate through the array
    for (int i = 0; i < size; ++i) {
        bool repeated = false;

        // Check if the current element is repeated
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] == arr[j]) {
                repeated = true;
                break;
            }
        }

        // If the element is repeated, copy it to the output array
        if (repeated) {
            out[count] = arr[i];
            ++count;
        }
    }

    // Return the number of elements copied to the output array
    return count;
}

int main() {
    // Test cases
    const int size1 = 1;
    int arr1[size1] = {123};
    int out1[size1] = {0};
    int r1 = filter_repeated(arr1, size1, out1);
    print_array(out1, r1);

    const int size2 = 3;
    int arr2[size2] = {1, 2, 3};
    int out2[1] = {0};
    int r2 = filter_repeated(arr2, size2, out2);
    print_array(out2, r2);

    const int size3 = 9;
    int arr3[size3] = {1, 2, 3, 1, 2, 3, 1, 2, 3};
    int out3[size3];
    int r3 = filter_repeated(arr3, size3, out3);
    print_array(out3, r3);

    const int size4 = 5;
    const int arr4[size4] = {1, 2, 3, 2, 1};
    int out4[size4 - 1] = {0};
    int r4 = filter_repeated(arr4, size4, out4);
    print_array(out4, r4);

    const int size5 = 5;
    const int arr5[size5] = {10, 30, 30, 30, 20};
    int out5[size5 - 2] = {0};
    int r5 = filter_repeated(arr5, size5, out5);
    print_array(out5, r5);

    const int size6 = 20;
    const int arr6[size6] = {1, -7, 7, 1, 8, -8, 0, 1, -2, 2, -2, 3, 11, 123, 12, 12, -123, 898, 10, 0};
    int out6[20] = {0};
    int r6 = filter_repeated(arr6, size6, out6);
    print_array(out6, r6);

    return 0;
}
