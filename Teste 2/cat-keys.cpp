#include <iostream>
#include <list>
#include <map>
#include <string>
#include <climits>
using namespace std;

string cat_keys(list<map<string, unsigned>> lst) {
    // Initialize variables to store the map with the minimum unsigned value
    map<string, unsigned> min_map;
    unsigned min_value = UINT_MAX;

    // Iterate through the list of maps
    for (const auto& m : lst) {
        // Find the minimum value in the current map
        for (const auto& pair : m) {
            if (pair.second < min_value) {
                min_value = pair.second;
                min_map = m;
            }
        }
    }

    // Concatenate all keys in the map with the minimum value
    string result;
    for (const auto& pair : min_map) {
        result += pair.first;
    }

    return result;
}

// Example usage
int main() {
    list<map<string, unsigned>> m2 = {
        { {"s1", 13}, {"s2", 2} }
    };
    cout << cat_keys(m2) << endl; // s1s2

    list<map<string, unsigned>> m1 = {
        { {"s1", 1} }
    };
    cout << cat_keys(m1) << endl; // s1

    list<map<string, unsigned>> m3 = {
        { {"s1", 13}, {"s2", 2} }, 
        { {"s3", 3}, {"s4", 4} }, 
        { {"s5", 16} }
    };
    cout << cat_keys(m3) << endl; // s1s2

    list<map<string, unsigned>> m4 = {
        { {"s1", 13}, {"s2", 4} }, 
        { {"s3", 3}, {"s4", 4} }
    };
    cout << cat_keys(m4) << endl; // s3s4

    return 0;
}
