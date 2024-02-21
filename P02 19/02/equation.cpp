#include <iostream>
#include <cmath>
#include <iomanip> // for std::setprecision
#include <limits> // for std::numeric_limits

using namespace std;

int solve_eq(int a, int b, int c, double& x1, double& x2) {
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        x1 = x2 = std::numeric_limits<double>::quiet_NaN();
        return 0;
    } else if (discriminant == 0) {
        x1 = -b / (2.0 * a);
        x2 = std::numeric_limits<double>::quiet_NaN();
        return 1;
    } else {
        x1 = (-b - std::sqrt(discriminant)) / (2.0 * a);
        x2 = (-b + std::sqrt(discriminant)) / (2.0 * a);
        return 2;
    }
}

int main() {
    double x1, x2;

    int r = solve_eq(1, 1, 0, x1, x2);
    std::cout << r << ' ' << std::fixed << std::setprecision(7) << x1 << ' ' << x2 << '\n';

    r = solve_eq(1, -2, 1, x1, x2);
    std::cout << r << ' ' << std::fixed << std::setprecision(7) << x1 << ' ' << x2 << '\n';

    r = solve_eq(1, 1, 1, x1, x2);
    std::cout << r << ' ' << std::fixed << std::setprecision(7) << x1 << ' ' << x2 << '\n';

    r = solve_eq(1, -1, 0, x1, x2);
    std::cout << r << ' ' << std::fixed << std::setprecision(7) << x1 << ' ' << x2 << '\n';

    r = solve_eq(3, 4, -2, x1, x2);
    std::cout << r << ' ' << std::fixed << std::setprecision(7) << x1 << ' ' << x2 << '\n';

    return 0;
}
