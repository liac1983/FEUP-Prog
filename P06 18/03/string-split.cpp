#include <iostream>
#include <vector>
#include <string>
#include "print_string.h"

void split(const std::string& s, std::vector<std::string>& v) {
    // Clear the vector before starting
    v.clear();
    
    // Find the first non-space character
    size_t startPos = s.find_first_not_of(' ');
    
    // Continue splitting until there are no more non-space characters
    while (startPos != std::string::npos) {
        // Find the next space character
        size_t endPos = s.find(' ', startPos);
        
        // Extract the substring between startPos and endPos
        std::string substring = s.substr(startPos, endPos - startPos);
        
        // Add the substring to the vector
        v.push_back(substring);
        
        // Find the next non-space character
        startPos = s.find_first_not_of(' ', endPos);
    }
}

int main() {
    // Test cases
    std::string s1 = "";
    std::vector<std::string> v1;
    split(s1, v1);
    print(v1);

    std::string s2 = "    ";
    std::vector<std::string> v2;
    split(s2, v2);
    print(v2);

    std::string s3 = "  a b  c ";
    std::vector<std::string> v3;
    split(s3, v3);
    print(v3);

    std::string s4 = "C++ LEIC FCUP FEUP";
    std::vector<std::string> v4;
    split(s4, v4);
    print(v4);

    std::string s5 = "       C++        ";
    std::vector<std::string> v5;
    split(s5, v5);
    print(v5);

    return 0;
}
