#include <iostream>
using namespace std;

int main() {
    int r = 123;
    while(true) {
        if (r % 3 == 0) {
            r += 2;
            continue;
        }
        if (r % 3 == 1) {
            break;
        }
        r += r % 2 == 0 ? 1 : 2;
    }
    cout << r ;
    return 0;
}