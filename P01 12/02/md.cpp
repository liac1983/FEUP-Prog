#include <iostream>
#include <cmath>

using namespace std;

int manhattanDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    int n;
    
    cin >> n;

    int totalDistance = 0;
    int x1, y1, x2, y2;
    
    cin >> x1 >> y1;
    for (int i = 1; i < n; ++i) {
        cin >> x2 >> y2;
        totalDistance += manhattanDistance(x1, y1, x2, y2);
        x1 = x2;
        y1 = y2;
    }

    cout << totalDistance << endl;

    return 0;
}
