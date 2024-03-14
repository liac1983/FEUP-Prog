#include <iostream>


int str_length(const char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        ++length;
    }
    return length;
}


void str_copy(char dest[], const char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
}


char* repeat(const char str[], int n) {
    
    if (str[0] == '\0') {
        char* result = new char[1];
        result[0] = '\0';
        return result;
    }

 
    int length = str_length(str) * n;

   
    char* result = new char[length + 1];

    for (int i = 0; i < n; ++i) {
        str_copy(result + i * str_length(str), str);
    }

    
    result[length] = '\0';

    return result;
}

int main() {
    const char str1[] = "H e l l o";
    char* r1 = repeat(str1, 2);
    std::cout << "\"" << r1 << "\"\n";
    delete[] r1;

    const char str2[] = "C++";
    char* r2 = repeat(str2, 1);
    std::cout << "\"" << r2 << "\"\n";
    delete[] r2;

    const char str3[] = "";
    char* r3 = repeat(str3, 99);
    std::cout << "\"" << r3 << "\"\n";
    delete[] r3;

    const char str4[] = "C/C++@LEIC.";
    char* r4 = repeat(str4, 5);
    std::cout << "\"" << r4 << "\"\n";
    delete[] r4;

    const char str5[] = "x";
    char* r5 = repeat(str5, 15);
    std::cout << "\"" << r5 << "\"\n";
    delete[] r5;

    return 0;
}
