#include <iostream>
#include <iomanip>
#include "Student.h"

using namespace std;

int main() {
    // Test case 1
    {
        Student s("Andre Meira", "up201404877", 20, 18, 10);
        cout << "[" << s.get_id() << "]/";
        cout << fixed << setprecision(2) << s.actual_grade() << endl;
    }

    // Test case 2
    {
        Student s("John Doe", "up19790007", 20, 20, 20);
        cout << "[" << s.get_id() << "]/";
        cout << fixed << setprecision(2) << s.actual_grade() << endl;
    }

    // Test case 3
    {
        Student s("Graham Chapman", "up19790077", 10, 10, 10);
        cout << "[" << s.get_id() << "]/";
        cout << fixed << setprecision(2) << s.actual_grade() << endl;
    }

    // Test case 4
    {
        Student s("John Cleese", "up19790077", 8, 7, 13);
        cout << "[" << s.get_id() << "]/";
        cout << fixed << setprecision(2) << s.actual_grade() << endl;
    }

    return 0;
}
