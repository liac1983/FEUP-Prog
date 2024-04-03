#include <iostream>
using namespace std;

int diff_letters(const char a[], const char b[], char out[]) {
    // Array to keep track of the occurrence of each letter
    int count[26] = {0};

    // Iterate through string 'a'
    for (int i = 0; a[i] != '\0'; ++i) {
        if (isalpha(a[i])) {
            int index = tolower(a[i]) - 'a';
            ++count[index];
        }
    }

    // Iterate through string 'b'
    for (int i = 0; b[i] != '\0'; ++i) {
        if (isalpha(b[i])) {
            int index = tolower(b[i]) - 'a';
            ++count[index];
        }
    }

    int diffCount = 0;

    // Populate 'out' with letters that occur only once
    for (int i = 0; i < 26; ++i) {
        if (count[i] == 1) {
            out[diffCount++] = 'a' + i;
        }
    }

    out[diffCount] = '\0'; // Null-terminate 'out'

    return diffCount;
}

int main() {
    // Test cases
    char out1[26 + 1];
    int n1 = diff_letters("+LEIC", "c++", out1);
    cout << n1 << " \"" << out1 << "\"\n";

    char out2[26 + 1];
    int n2 = diff_letters("LEIC @ UP", "XY ZZZ++", out2);
    cout << n2 << " \"" << out2 << "\"\n";

    char out3[26 + 1];
    int n3 = diff_letters("", "abcdefghi JKLMNOPQRSTUVWXyz", out3);
    cout << n3 << " \"" << out3 << "\"\n";

    char out4[26 + 1];
    int n4 = diff_letters("JKLMNOPQRSTUVWXyz ABCDE fghi", "abcdefghi JKLMNOPQRSTUVWXyz", out4);
    cout << n4 << " \"" << out4 << "\"\n";

    char out5[26 + 1];
    int n5 = diff_letters("J LMNOP RSTUVWXyz ABCDE fghi", "a cdefghi JKL NOPQRS UVWXy", out5);
    cout << n5 << " \"" << out5 << "\"\n";

    char out6[26 + 1];
    int n6 = diff_letters("abcdefgh 12345 JKLMNOPQRSTUVWXyz abcdefgh JKLMNOPQRSTUVWXyz", "zzzz abcdefghi JKLMNOPQRSTUVWXz", out6);
    cout << n6 << " \"" << out6 << "\"\n";

    return 0;
}
