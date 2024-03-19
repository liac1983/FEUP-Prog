#include <iostream>
using namespace std;

int main() {
    int h;
    int m;
    int delta;
    std::cin >> h;
    std::cin >> m;
    std::cin >> delta;

    int rh = h;
    int rm = m + delta;

    if (rm >= 60) {
        rh += rm / 60;
        rm %= 60;
    }
    
    rh %= 24; // Adjusting hours if it exceeds 23

    std::cout << rh << ' ' << rm << '\n';
    return 0;
}
