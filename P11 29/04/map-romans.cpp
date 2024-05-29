#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unsigned roman_to_arab(const string& roman) {
    vector<pair<char, unsigned>> roman_to_int = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    
    unordered_map<char, unsigned> roman_map(roman_to_int.begin(), roman_to_int.end());
    
    unsigned result = 0;
    unsigned prev = 0;
    
    for (auto it = roman.rbegin(); it != roman.rend(); ++it) {
        unsigned current = roman_map[*it];
        if (current < prev)
            result -= current;
        else
            result += current;
        prev = current;
    }
    
    return result;
}

int main() {
    string r1 = "XV";
    string r2 = "LXXXIV";
    string r3 = "CMLXIV";
    string r4 = "MMMCMXCIX";
    string r5 = "MMMDCCCLXXXVIII";
    
    cout << roman_to_arab(r1) << '\n'; // Output: 15
    cout << roman_to_arab(r2) << '\n'; // Output: 84
    cout << roman_to_arab(r3) << '\n'; // Output: 964
    cout << roman_to_arab(r4) << '\n'; // Output: 3999
    cout << roman_to_arab(r5) << '\n'; // Output: 3888
    
    return 0;
}
