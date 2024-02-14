#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int countOnes(int num) {
    int count = 0;
    while (num > 0) {
        if (num & 1) {
            ++count;
        }
        num >>= 1;
    }
    return count;
}

bool isPernicious(int num) {
    return isPrime(countOnes(num));
}

void printPerniciousPrimes(int a, int b) {
    
    for (int i = a; i <= b; ++i) {
        if (isPrime(i) && isPernicious(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int a, b;
    
    cin >> a >> b;

    printPerniciousPrimes(a, b);

    return 0;
}
