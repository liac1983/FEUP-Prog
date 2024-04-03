#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <sstream>
#include "show_file.h" // Assume que o arquivo show_file.h está na mesma pasta do código-fonte

void calc_medians(const std::string& input_fname, const std::string& output_fname) {
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
        if (line.empty() || line[0] == '#') {
            // Ignore empty lines and comment lines
            continue;
        }

        std::istringstream iss(line);
        std::string identifier;
        iss >> identifier;

        double value;
        std::vector<double> values;
        while (iss >> value) {
            values.push_back(value);
        }

        if (!values.empty()) {
            std::sort(values.begin(), values.end());

            double median;
            if (values.size() % 2 == 1) {
                median = values[values.size() / 2];
            } else {
                median = (values[values.size() / 2 - 1] + values[values.size() / 2]) / 2.0;
            }

            output_file << identifier << ' ' << std::fixed << std::setprecision(1) << median << '\n';
        }
    }

    input_file.close();
    output_file.close();
}

int main() {
    // Teste com os arquivos fornecidos
    calc_medians("ex5/p5_test1.txt", "ex5/p5_test1_out.txt");
    show_file("ex5/p5_test1_out.txt");

    calc_medians("ex5/p5_test2.txt", "ex5/p5_test2_out.txt");
    show_file("ex5/p5_test2_out.txt");

    calc_medians("ex5/p5_test3.txt", "ex5/p5_test3_out.txt");
    show_file("ex5/p5_test3_out.txt");

    calc_medians("ex5/p5_test4.txt", "ex5/p5_test4_out.txt");
    show_file("ex5/p5_test4_out.txt");

    calc_medians("ex5/p5_test5.txt", "ex5/p5_test5_out.txt");
    show_file("ex5/p5_test5_out.txt");

    return 0;
}
