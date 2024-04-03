#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <string>
#include <cmath>
#include "show_file.h" // Assume que o arquivo show_file.h está na mesma pasta do código-fonte

void maximum(const std::string& input_fname, const std::string& output_fname) {
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

    double max_value = -std::numeric_limits<double>::infinity();
    int count = 0;
    double value;
    while (input_file >> value) {
        // Round value to 3 decimal places
        value = std::round(value * 1000.0) / 1000.0;

        // Write rounded value to output file
        output_file << std::fixed << std::setprecision(3) << value << '\n';

        // Update max_value if necessary
        max_value = std::max(max_value, value);

        // Increment count
        count++;
    }

    // Write count and max_value to output file
    output_file << "count=" << count << "/max=" << max_value << '\n';

    input_file.close();
    output_file.close();
}

int main() {
    // Teste com os arquivos fornecidos
    maximum("ex4/p4_test1.txt", "ex4/p4_test1_out.txt");
    show_file("ex4/p4_test1_out.txt");

    maximum("ex4/p4_test2.txt", "ex4/p4_test2_out.txt");
    show_file("ex4/p4_test2_out.txt");

    maximum("ex4/p4_test3.txt", "ex4/p4_test3_out.txt");
    show_file("ex4/p4_test3_out.txt");

    maximum("ex4/p4_test4.txt", "ex4/p4_test4_out.txt");
    show_file("ex4/p4_test4_out.txt");

    return 0;
}
