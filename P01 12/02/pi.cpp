#include <iostream>
#include <iomanip>

using namespace std;

double calculatePi(int k) {
    double pi = 0.0;
    for (int n = 0; n <= k; ++n) {
        pi += (n % 2 == 0 ? 1 : -1) / (2.0 * n + 1);
    }
    return 4 * pi;
}

int main() {
    int k, d;
    cin >> k >> d;

    double approximation = calculatePi(k);

    cout << fixed << setprecision(d) << approximation << endl;

    return 0;
}
