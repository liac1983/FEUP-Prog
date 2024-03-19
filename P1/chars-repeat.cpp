#include <iostream>
using namespace std;

char* chars_repeat(const char str[], int min_repeat) {
    // Get the length of the input string
    int length = 0;
    while (str[length] != '\0') {
        ++length;
    }

    // Allocate memory for the new string
    char* result = new char[length * (length + 1) / 2 + 1]; // Maximum possible length of the resulting string
    int index = 0;

    // Iterate through each character of the input string
    for (int i = 0; i < length; ++i) {
        int repeat = (i < min_repeat) ? min_repeat : i + 1; // Determine the number of times the character should be repeated
        for (int j = 0; j < repeat; ++j) {
            result[index++] = str[i]; // Append the character to the resulting string
        }
    }
    
    result[index] = '\0'; // Null-terminate the resulting string
    return result;
}

int main() {
    // Test cases
    const char str1[] = "LEIC";
    char *r1 = chars_repeat(str1, 2);
    cout << "\"" << r1 << "\"\n";
    delete[] r1;

    const char str2[] = "";
    char *r2 = chars_repeat(str2, 100);
    cout << "\"" << r2 << "\"\n";
    delete[] r2;

    const char str3[] = "LEIC";
    char *r3 = chars_repeat(str3, 0);
    cout << "\"" << r3 << "\"\n";
    delete[] r3;

    const char str4[] = "C";
    char *r4 = chars_repeat(str4, 0);
    cout << "\"" << r4 << "\"\n";
    delete[] r4;

    const char str5[] = "C+ + !";
    char *r5 = chars_repeat(str5, 1);
    cout << "\"" << r5 << "\"\n";
    delete[] r5;

    const char str6[] = "LEIC@UP";
    char *r6 = chars_repeat(str6, 5);
    cout << "\"" << r6 << "\"\n";
    delete[] r6;

    const char str7[] = "C/C++@LEIC.";
    char *r7 = chars_repeat(str7, 4);
    cout << "\"" << r7 << "\"\n";
    delete[] r7;

    return 0;
}
