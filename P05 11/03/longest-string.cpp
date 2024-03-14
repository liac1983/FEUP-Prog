#include <iostream>

const char* longest(const char* pa[]) {
    
    const char* longestS = pa[0];
    int maxLength = 0;

    
    int i = 0;
    while (pa[i] != nullptr) {
        
        int currentLength = 0;
        const char* current = pa[i];
        while (*current != '\0') {
            ++currentLength;
            ++current;
        }

        
        if (currentLength >= maxLength) {
            maxLength = currentLength;
            longestS = pa[i];
        }

        ++i;
    }

    
    return longestS;
}

int main() {
    // Test cases
    const char* pa1[] = { "C++", nullptr };
    std::cout << "\"" << longest(pa1) << "\"\n";

    const char* pa2[] = { "", "0123", "Hello", "world", "!", nullptr };
    std::cout << "\"" << longest(pa2) << "\"\n";

    const char* pa3[] = { "Hello_world", "Hello", "Hello world", nullptr };
    std::cout << "\"" << longest(pa3) << "\"\n";

    const char* pa4[] = { "Hello world!", "Hello_world", "Hello world", nullptr };
    std::cout << "\"" << longest(pa4) << "\"\n";

    const char* pa5[] = { "C++", "Python", "Java", "C#", "Julia", "Rust", "Haskell", "Typescript", "OCaml", "Fortran", nullptr };
    std::cout << "\"" << longest(pa5) << "\"\n";

    return 0;
}
