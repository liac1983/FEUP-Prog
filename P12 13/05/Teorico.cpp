#include <iostream>
using namespace std;

int main() {
    int i = 0;
    auto f = [ & ] (int x) {
        i++; return x + i;
    };
    cout << f(0) << f(1) << f(2) << ' ';
    auto g = [ = ] (int x) {
        return x + i;
    };
    cout << g(0) << g(1) << g(2) << '\n';
    return 0;
}