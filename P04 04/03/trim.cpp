#include <iostream>

void trim(char s[]) {
    // Find the first non-space character from the beginning
    int start = 0;
    while (s[start] == ' ')
        start++;

    
    if (s[start] == '\0') {
        s[0] = '\0';
        return;
    }

    // Find the last non-space character from the end
    int end = 0;
    while (s[end] != '\0')
        end++;
    end--;
    while (end >= 0 && s[end] == ' ')
        end--;

    for (int i = 0; i <= end - start; i++)
        s[i] = s[start + i];
    s[end - start + 1] = '\0'; 
}

int main() {
    char s[] = " abc! def? ";
    std::cout << "\"" << s << "\" => ";
    trim(s);
    std::cout << "\"" << s << "\"\n";

    char s2[] = "#abc";
    std::cout << "\"" << s2 << "\" => ";
    trim(s2);
    std::cout << "\"" << s2 << "\"\n";

    char s3[] = "    abc def";
    std::cout << "\"" << s3 << "\" => ";
    trim(s3);
    std::cout << "\"" << s3 << "\"\n";

    char s4[] = "abc def.   ";
    std::cout << "\"" << s4 << "\" => ";
    trim(s4);
    std::cout << "\"" << s4 << "\"\n";

    char s5[] = "   ";
    std::cout << "\"" << s5 << "\" => ";
    trim(s5);
    std::cout << "\"" << s5 << "\"\n";

    char s6[] = "";
    std::cout << "\"" << s6 << "\" => ";
    trim(s6);
    std::cout << "\"" << s6 << "\"\n";

    char s7[] = " abc  _  def  _  ghi ";
    std::cout << "\"" << s7 << "\" => ";
    trim(s7);
    std::cout << "\"" << s7 << "\"\n";

    char s8[] = "a           ";
    std::cout << "\"" << s8 << "\" => ";
    trim(s8);
    std::cout << "\"" << s8 << "\"\n";

    return 0;
}
