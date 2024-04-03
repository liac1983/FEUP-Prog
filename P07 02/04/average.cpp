#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>

double average(const std::string& fname) {
    std::ifstream file(fname);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << fname << std::endl;
        return 0.0; // Return 0.0 to indicate failure
    }

    double sum = 0.0;
    double value;
    int count = 0;
    while(! file.eof()) {
        if (file >> value) {
            sum += value;
            count++;
        }
        else {
            file.clear(); // Clear error flags
            file.ignore(1); // Skip remaining characters
        }

    
    }
    
    return sum / count;
}

int main() {
    std::cout << std::fixed << std::setprecision(2);
    
    std::cout << average("ex6/p6_test1.txt") << '\n';
    std::cout << average("ex6/p6_test2.txt") << '\n';
    std::cout << average("ex6/p6_test3.txt") << '\n';
    std::cout << average("ex6/p6_test4.txt") << '\n';
    std::cout << average("ex6/p6_test5.txt") << '\n';

    return 0;
}
/*
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>

double average(const std::string& fname) {
    std::ifstream file(fname);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << fname << std::endl;
        return 0.0; // Return 0.0 to indicate failure
    }

    double sum = 0.0;
    double value;
    int count = 0;

    while (file >> value) {
        if (file.fail()) {
            // Clear the failbit to continue reading
            file.clear();
            // Skip the invalid input
            file.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
            continue;
        }
        sum += value;
        count++;
    }

    if (count == 0) {
        // No valid values found
        return 0.0;
    }

    return sum / count;
}

int main() {
    std::cout << std::fixed << std::setprecision(2);
    
    std::cout << average("ex6/p6_test1.txt") << '\n';
    std::cout << average("ex6/p6_test2.txt") << '\n';
    std::cout << average("ex6/p6_test3.txt") << '\n';
    std::cout << average("ex6/p6_test4.txt") << '\n';
    std::cout << average("ex6/p6_test5.txt") << '\n';

    return 0;
}*/
