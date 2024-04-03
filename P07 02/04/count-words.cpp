#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

int count(const std::string& fname, const std::string& word) {
    std::ifstream file(fname);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << fname << std::endl;
        return -1; // Return -1 to indicate failure
    }

    std::string line;
    int count = 0;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;
        while (iss >> token) {
            // Convert token and word to uppercase for case insensitive comparison
            std::string upperToken, upperWord;
            for (char c : token) {
                upperToken += std::toupper(c);
            }
            for (char c : word) {
                upperWord += std::toupper(c);
            }
            if (upperToken == upperWord) {
                count++;
            }
        }
    }

    file.close();
    return count;
}

int main() {
    std::cout << count("ex1/p1_test_a.txt", "THE") << '\n';    // 4
    std::cout << count("ex1/p1_test_a.txt", "0") << '\n';      // 1
    std::cout << count("ex1/p1_test_a.txt", "code") << '\n';   // 0
    std::cout << count("ex1/p1_test_b.txt", "Collider") << '\n'; // 6
    std::cout << count("ex1/p1_test_b.txt", "you") << '\n';    // 21
    return 0;
}
