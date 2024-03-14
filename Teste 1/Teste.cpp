#include <iostream>

using namespace std;

namespace a {
    int f(int x, int y=2) { return x+y; }
    double f(double x, double y) { return x - y; }
    double f(double x = 2.5) { return x;}

}

namespace b {
    char f(char x) { return x; }
    short f(short x=1) { return x+1; }
}

int f(int x) {
    return x;
}

int main() { 
    return 0;
}