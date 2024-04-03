#include <iostream>
#include <string>
#include <cctype>

bool pangram(const std::string& s, std::string& m) {
    bool letters[26] = {false}; // Array to keep track of letters occurrence
    
    // Check each character in the string
    for (char c : s) {
        if (std::isalpha(c)) { // Check if it's an alphabetic character
            letters[std::tolower(c) - 'a'] = true; // Mark the corresponding letter as present
        }
    }
    
    bool isPangram = true;
    m = "";
    
    // Check if all letters are present
    for (int i = 0; i < 26; ++i) {
        if (!letters[i]) {
            isPangram = false;
            m += static_cast<char>('a' + i); // Add the missing letter to m
        }
    }
    
    return isPangram;
}

int main() {
    // Test cases
    std::string s1 = "";
    std::string m1 = "";
    bool r1 = pangram(s1, m1);
    std::cout << "\"" << s1 << "\" " << std::boolalpha << r1 << " \"" << m1 << "\"\n";
    
    std::string s2 = "The quick brown fox jumps over the lazy dog";
    std::string m2 = "";
    bool r2 = pangram(s2, m2);
    std::cout << "\"" << s2 << "\" " << std::boolalpha << r2 << " \"" << m2 << "\"\n";
    
    std::string s3 = "A quick brown fox jumps over a classy dog";
    std::string m3 = "";
    bool r3 = pangram(s3, m3);
    std::cout << "\"" << s3 << "\" " << std::boolalpha << r3 << " \"" << m3 << "\"\n";
    
    std::string s4 = " abC dEf GhI jKl MnO pQr StU vWx yZ ";
    std::string m4 = "";
    bool r4 = pangram(s4, m4);
    std::cout << "\"" << s4 << "\" " << std::boolalpha << r4 << " \"" << m4 << "\"\n";
    
    std::string s5 = " Stu yZ abC GhI MnO pQr   ";
    std::string m5 = "";
    bool r5 = pangram(s5, m5);
    std::cout << "\"" << s5 << "\" " << std::boolalpha << r5 << " \"" << m5 << "\"\n";
    
    return 0;
}
