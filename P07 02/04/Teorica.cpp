#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    vector<string> a { "Portugal", "Spain", "France", "England"};
    vector<string> b;
    for (string& s : a) {
        if (s.length() > 6) {
            b.push_back(s);
            s = "-";
        }
    }
    for (string s : a) cout << s;
    cout << '\n';
    for (string s : b) cout << s;
    cout << '\n';

    return 0;
}