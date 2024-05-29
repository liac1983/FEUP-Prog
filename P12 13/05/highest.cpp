#include <iostream>
#include <map>
#include <list>
#include <string>
#include <numeric>

using namespace std;

string student_highest_avg(map<string, list<int>> m) {
    string top_student;
    double highest_avg = -1.0;

    for (const auto& entry : m) {
        const string& student = entry.first;
        const list<int>& grades = entry.second;

        double avg = static_cast<double>(accumulate(grades.begin(), grades.end(), 0)) / grades.size();
        
        if (avg > highest_avg) {
            highest_avg = avg;
            top_student = student;
        }
    }

    return top_student;
}

// Example main function for testing
int main() {
    map<string, list<int>> m1 = { {"Jerry", {10, 20, 15}} };
    cout << student_highest_avg(m1) << endl; // Should output: Jerry

    map<string, list<int>> m2 = { {"Elaine", {15, 18, 14, 16}}, {"Newman", {18, 12, 19}} };
    cout << student_highest_avg(m2) << endl; // Should output: Newman

    map<string, list<int>> m3 = { {"Whatley", {10, 10}}, {"Kramer", {11, 12, 14}}, {"Cosmo", { 15, 10, 13}} };
    cout << student_highest_avg(m3) << endl; // Should output: Cosmo

    map<string, list<int>> m4 = { {"Costanza", {0, 11}}, {"Frank", {8, 12}} };
    cout << student_highest_avg(m4) << endl; // Should output: Frank

    map<string, list<int>> m5 = { {"Frank", {10, 15}}, {"Costanza", {10, 14}} };
    cout << student_highest_avg(m5) << endl; // Should output: Frank

    return 0;
}
