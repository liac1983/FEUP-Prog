#include <iostream>


size_t s_length(const char s[]) {
    size_t length = 0;
    while (s[length] != '\0') {
        ++length;
    }
    return length;
}


void copy(char destination[], const char source[]) {
    size_t i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        ++i;
    }
    destination[i] = '\0';
}

char* duplicate(const char s[]) {
    
    size_t length = s_length(s);

    
    char* duplicateStr = new char[length + 1];

    
    copy(duplicateStr, s);

    return duplicateStr;
}

int main() {
    // Test cases
    char* s1 = duplicate("");
    std::cout << "\"" << s1 << "\"\n";
    delete[] s1;

    char* s2 = duplicate("a");
    std::cout << "\"" << s2 << "\"\n";
    delete[] s2;

    char* s3 = duplicate("C++");
    std::cout << "\"" << s3 << "\"\n";
    delete[] s3;

    char* s4 = duplicate("0123 456 789 @ abc");
    std::cout << "\"" << s4 << "\"\n";
    delete[] s4;

    return 0;
}
