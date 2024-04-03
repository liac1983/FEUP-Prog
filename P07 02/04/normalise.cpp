#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "print.h" // Assume que o arquivo print.h está na mesma pasta do código-fonte

void normalise(const std::string& input_fname, const std::string& output_fname) {
    std::ifstream input_file(input_fname);
    if (!input_file.is_open()) {
        std::cerr << "Failed to open input file: " << input_fname << std::endl;
        return;
    }

    std::ofstream output_file(output_fname);
    if (!output_file.is_open()) {
        std::cerr << "Failed to open output file: " << output_fname << std::endl;
        return;
    }

    std::string line;
    while (std::getline(input_file, line)) {
        // Check if the line contains only space characters
        bool contains_non_space = false;
        for (char c : line) {
            if (!std::isspace(c)) {
                contains_non_space = true;
                break;
            }
        }

        // Skip lines with only space characters
        if (!contains_non_space) {
            continue;
        }

        // Remove leading and trailing spaces
        size_t first_non_space = line.find_first_not_of(" ");
        size_t last_non_space = line.find_last_not_of(" ");
        line = line.substr(first_non_space, last_non_space - first_non_space + 1);

        // Convert to uppercase
        for (char& c : line) {
            c = std::toupper(c);
        }

        // Write the normalized line to the output file
        output_file << line << '\n';
    }

    input_file.close();
    output_file.close();
}

int main() {
    // Teste com os arquivos fornecidos
    normalise("ex3/p3_test1.txt", "ex3/p3_test1_out.txt");
    print("ex3/p3_test1_out.txt");

    normalise("ex3/p3_test2.txt", "ex3/p3_test2_out.txt");
    print("ex3/p3_test2_out.txt");

    normalise("ex3/p3_test3.txt", "ex3/p3_test3_out.txt");
    print("ex3/p3_test3_out.txt");

    normalise("ex3/p3_test4.txt", "ex3/p3_test4_out.txt");
    print("ex3/p3_test4_out.txt");

    normalise("ex3/p3_test5.txt", "ex3/p3_test5_out.txt");
    print("ex3/p3_test5_out.txt");

    return 0;
}
