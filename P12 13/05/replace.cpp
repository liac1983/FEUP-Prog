#include <iostream>
#include <string>
#include <map>

using namespace std;

void replace(const map<char, char>& r, string& s) {
    for (char& c : s) {
        auto it = r.find(c);
        if (it != r.end()) {
            c = it->second;
        }
    }
}

int main() {
    // Teste 1
    string s1 = "C / C++ @ LEIC";
    replace({ {'C', 'z'}, {'+', '-'}, {'L', 'X'}}, s1);
    cout << s1 << '\n'; // Saída: z / z-- @ XEIz

    // Teste 2
    string s2 = "C / C++ @ LEIC";
    replace({ }, s2);
    cout << s2 << '\n'; // Saída: C / C++ @ LEIC

    // Teste 3
    string s3 = "A B C D E F";
    replace({ {' ', '_'}}, s3);
    cout << s3 << '\n'; // Saída: A_B_C_D_E_F

    // Teste 4
    string s4 = "A B C D E F";
    replace({ {'_', ' '}, {'A', '?'}, {'?', '!'}, {'F', '!'}}, s4);
    cout << s4 << '\n'; // Saída: ? B C D E !
    
    return 0;
}
