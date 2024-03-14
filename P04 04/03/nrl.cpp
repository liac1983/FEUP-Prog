#include <iostream>

int nrl(const char s[], char low[]) {
    const int ALPHABET_SIZE = 26;
    int freq[ALPHABET_SIZE] = {0}; // Initialize frequency count array to zeros

    
    int len = 0;
    while (s[len] != '\0') {
        // Check if the character is a letter (uppercase or lowercase)
        if ((s[len] >= 'a' && s[len] <= 'z') || (s[len] >= 'A' && s[len] <= 'Z')) {
            char c = tolower(s[len]); // Convert to lowercase
            freq[c - 'a']++; // Increment the count of the corresponding letter
        }
        len++;
    }

    int count = 0; // Counter for non-repeated letters

    // Traverse the frequency array to find non-repeated letters and populate 'low'
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (freq[i] == 1) { // If the letter occurs only once
            low[count++] = 'a' + i; // Add the lowercase version to 'low'
        }
    }
    low[count] = '\0'; // Null-terminate 'low'

    return count; // Return the number of non-repeated letters
}

int main() {
    const char s1[] = "";
    char l1[27] = {0}; // Initialize 'low' with zeros
    int r1 = nrl(s1, l1);
    std::cout << '\"' << s1 << "\" " << r1 << " \"" << l1 << "\"\n";

    const char s2[] = "  F C U P  F E U P  Porto  ";
    char l2[27] = {0}; // Initialize 'low' with zeros
    int r2 = nrl(s2, l2);
    std::cout << '\"' << s2 << "\" " << r2 << " \"" << l2 << "\"\n";

    const char s3[] = " abC dEf GhI jKl MnO pQr StU vWx yZ ";
    char l3[27] = {0}; // Initialize 'low' with zeros
    int r3 = nrl(s3, l3);
    std::cout << '\"' << s3 << "\" " << r3 << " \"" << l3 << "\"\n";

    const char s4[] = " abC dEf GhI jKl MnO pQr StU vWx yZ ABc DeF gHi JkL mNo PqR sTu VwX Yz";
    char l4[27] = {0}; // Initialize 'low' with zeros
    int r4 = nrl(s4, l4);
    std::cout << '\"' << s4 << "\" " << r4 << " \"" << l4 << "\"\n";

    const char s5[] = "The quick brown fox jumps over the lazy dog";
    char l5[27] = {0}; // Initialize 'low' with zeros
    int r5 = nrl(s5, l5);
    std::cout << '\"' << s5 << "\" " << r5 << " \"" << l5 << "\"\n";

    return 0;
}
