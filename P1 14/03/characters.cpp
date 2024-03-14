#include <iostream>

int main() {
    char ch;

    std::cin >> ch;

    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        std::cout << "LETTER";
    } else if (ch >= '0' && ch <= '9') {
        std::cout << "DIGIT";
    } else {
        std::cout << "OTHER";
    }

    return 0;
}
