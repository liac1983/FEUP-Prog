#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <string>
#include "show_file.h"

using namespace std;

void average(const string& input_fname, const string& output_fname) {
    ifstream infile(input_fname);
    ofstream outfile(output_fname);

    if (!infile.is_open() || !outfile.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    string line;
    int line_count = 0;

    while (getline(infile, line)) {
        stringstream ss(line);
        double num, sum = 0;
        int count = 0;

        while (ss >> num) {
            sum += num;
            count++;
        }

        if (count > 0) {
            double avg = sum / count;
            outfile << fixed << setprecision(3) << avg << endl;
        }

        line_count++;
    }

    outfile << "lines=" << line_count << endl;

    infile.close();
    outfile.close();
}

int main() {
    // Example usage with the provided test cases
    average("ex1a/p1a-1.txt", "p1a-1_out.txt");
    show_file("p1a-1_out.txt");
    average("ex1a/p1a-2.txt", "p1a-2_out.txt");
    show_file("p1a-2_out.txt");
    average("ex1a/p1a-3.txt", "p1a-3_out.txt");
    show_file("p1a-3_out.txt");
    average("ex1a/p1a-4.txt", "p1a-4_out.txt");
    show_file("p1a-4_out.txt");

    return 0;
}
