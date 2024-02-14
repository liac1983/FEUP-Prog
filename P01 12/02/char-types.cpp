#include <iostream>
#include <cctype>

using namespace std;

int main() {
    int n;
    cin >> n;

    int letters = 0, digits = 0, others = 0;
    char c;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        if (isalpha(c)) {
            letters++;
        } else if (isdigit(c)) {
            digits++;
        } else {
            others++;
        }
    }

    cout <<letters << " ";
    cout << digits << " ";
    cout << others << " ";

    return 0;
}
