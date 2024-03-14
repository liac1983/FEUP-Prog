#include <iostream>

using namespace std;

int main() {
    int n; cout << "n? "; cin >> n;
    double* arr = new double[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    delete [] arr;
    for (int i = n - 1; i >= 0; i--) cout << arr[i] << '\n';
    return 0;
}