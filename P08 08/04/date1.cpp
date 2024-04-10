#include <iostream>
#include <iomanip>

using namespace std;

// A simple class Date definition
class Date {
  public:
    // constructors
    Date();                             // Default constructor
    Date(int year, int month, int day); // Constructor with parameters
    // accessors
    int get_year() const;
    int get_month() const;
    int get_day() const;
    // write the date as "yyyy/mm/dd"
    void write() const; 
  private:
    int year;
    int month;
    int day;
    // compute the number of days of month/year, for internal use only
    static int num_days(int year, int month);
};

Date::Date() : year(1), month(1), day(1) {}

Date::Date(int year, int month, int day) : year(year), month(month), day(day) {}

int Date::get_year() const {
    return year;
}

int Date::get_month() const {
    return month;
}

int Date::get_day() const {
    return day;
}

void Date::write() const {
    std::cout << std::setfill('0')
              << std::setw(4) << year << '/'
              << std::setw(2) << month << '/'
              << std::setw(2) << day;
}

int Date::num_days(int year, int month) {
    int n_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        return 29;
    return n_days[month - 1];
}

bool is_before(const Date& date1, const Date& date2) {
    if (date1.get_year() < date2.get_year())
        return true;
    else if (date1.get_year() == date2.get_year()) {
        if (date1.get_month() < date2.get_month())
            return true;
        else if (date1.get_month() == date2.get_month()) {
            if (date1.get_day() < date2.get_day())
                return true;
        }
    }
    return false;
}

int main() {
    Date d1; d1.write(); cout << '\n';
    Date d2(2020, 2, 29); d2.write(); cout << '\n';
    Date d3(1925, 4, 30); d3.write(); cout << '\n';
    Date d4, d5(2022,4,29); d4.write(); cout << '-' << boolalpha << is_before(d4, d5) << '\n';
    Date d6(2023,10,31), d7(2022, 4, 29); d6.write(); cout << '-' << boolalpha << is_before(d6, d7) << '\n';
    return 0;
}
