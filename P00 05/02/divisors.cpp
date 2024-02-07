#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int d = 1; d <= n / 2; ++d) {
        if (n % d == 0) {
            cout << d << " ";
        }
    }
    cout << "\n";
    return 0;
}