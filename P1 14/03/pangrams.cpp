#include <iostream>

char custom_toupper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

bool custom_alpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool pangram(const char s[], char m[]) {
    // Internal array to keep track of letters
    bool letters[26] = {false};

    
    for (const char* p = s; *p != '\0'; ++p) {
        if (custom_alpha(*p)) {
            int index = custom_toupper(*p) - 'A';
            letters[index] = true;
        }
    }

    
    int missingCount = 0;
    for (int i = 0; i < 26; ++i) {
        if (!letters[i]) {
            m[missingCount++] = 'a' + i;
        }
    }
    m[missingCount] = '\0'; 

    // Check if all letters are present
    for (int i = 0; i < 26; ++i) {
        if (!letters[i]) {
            return false; // Not a pangram
        }
    }
    
    return true; // Pangram
}

int main() {
    char s1[] = "";
    char m1[27] = { -1 };
    bool r1 = pangram(s1, m1);
    std::cout << '\"' << s1 << "\" " << std::boolalpha << r1 << " \"" << m1 << "\"\n";

    char s2[] = "The quick brown fox jumps over the lazy dog";
    char m2[27] = { -1 };
    bool r2 = pangram(s2, m2);
    std::cout << '\"' << s2 << "\" " << std::boolalpha << r2 << " \"" << m2 << "\"\n";

    char s3[] = "A quick brown fox jumps over a classy dog";
    char m3[27] = { -1 };
    bool r3 = pangram(s3, m3);
    std::cout << '\"' << s3 << "\" " << std::boolalpha << r3 << " \"" << m3 << "\"\n";

    char s4[] = " abC dEf GhI jKl MnO pQr StU vWx yZ ";
    char m4[27] = { -1 };
    bool r4 = pangram(s4, m4);
    std::cout << '\"' << s4 << "\" " << std::boolalpha << r4 << " \"" << m4 << "\"\n";

    char s5[] = " Stu yZ abC GhI MnO pQr   ";
    char m5[27] = { -1 };
    bool r5 = pangram(s5, m5);
    std::cout << '\"' << s5 << "\" " << std::boolalpha << r5 << " \"" << m5 << "\"\n";

    return 0;
}
