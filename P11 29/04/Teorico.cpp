#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v { 10, 20, 30, 40, 50, 60};
    v.erase(v.begin());
    v.insert(v.begin() + 1, 99);
    v.erase(v.end() - 2);
    v.insert(v.end() - 1, 99);
    for (int x : v) {
        cout << x << ' ';
    }
    return 0;
}