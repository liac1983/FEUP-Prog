#include <iostream>

using namespace std;

int main() {
    int a[4] = {0,1,2,3};
    int* b = new int[4] {3,2,1,0};
    int i;
    std::cin >> i;
    if(--b[a[i]] != 0)
        delete [] b;
    return 0;
}
