#include <iostream>

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void advance(int delta, int& d, int& m, int& y) {
    while (delta > 0) {
        int days_in_month;

        // Determine number of days in the current month
        if (m == 2) {
            days_in_month = isLeapYear(y) ? 29 : 28;
        } else if (m == 4 || m == 6 || m == 9 || m == 11) {
            days_in_month = 30;
        } else {
            days_in_month = 31;
        }

        // Advance to the next month if necessary
        if (d + delta > days_in_month) {
            delta -= (days_in_month - d + 1);
            d = 1;
            if (m == 12) {
                m = 1;
                y++;
            } else {
                m++;
            }
        } else {
            // Just increment the day
            d += delta;
            delta = 0;
        }
    }
}

int main() {
    int d, m, y;

    d = 1; m = 1; y = 2022;
    advance(0, d, m, y);
    std::cout << d << ' ' << m << ' ' << y << '\n';

    d = 1; m = 10; y = 2022;
    advance(10, d, m, y);
    std::cout << d << ' ' << m << ' ' << y << '\n';

    d = 2; m = 6; y = 2022;
    advance(31, d, m, y);
    std::cout << d << ' ' << m << ' ' << y << '\n';

    d = 2; m = 7; y = 2022;
    advance(31, d, m, y);
    std::cout << d << ' ' << m << ' ' << y << '\n';

    d = 25; m = 2; y = 2000;
    advance(4, d, m, y);
    std::cout << d << ' ' << m << ' ' << y << '\n';

    d = 25; m = 2; y = 2001;
    advance(4, d, m, y);
    std::cout << d << ' ' << m << ' ' << y << '\n';

    d = 2; m = 12; y = 1900;
    advance(365 + 5, d, m, y);
    std::cout << d << ' ' << m << ' ' << y << '\n';

    d = 31; m = 3; y = 1903;
    advance(365 + 366 + 30 + 5, d, m, y);
    std::cout << d << ' ' << m << ' ' << y << '\n';

    return 0;
}
