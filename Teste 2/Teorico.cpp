#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
#include <stdexcept>

using namespace std;

int f(int a, int b) {
    if (a < b)
        throw range_error("a<b");
    return a - b;
}




int main() {
    try {
        cout << f(5,2) << '|';
        cout << f(3,3) << '|';
        cout << f(1,5) << '|';
    }
    catch (runtime_error& e) { cout << e.what(); }
    catch (...) {cout << "error"; }
    

    return 0;
}