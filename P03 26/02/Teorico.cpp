#include <iostream>

using namespace std;

struct data {
    double x;
    double y;
};

void f(const data& a, data& b) {
    a.y *= b.x - a.y;
}

int main() {

    return 0;
}