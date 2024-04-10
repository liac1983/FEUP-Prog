#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

class Date {
public:
    // constructors
    Date();
    Date(int year, int month, int day);
    Date(const std::string& year_month_day);
    // accessors
    int get_year() const;
    int get_month() const;
    int get_day() const;
    // other methods
    bool is_valid() const; // tests date validity
    void write() const;    // writes the date as "yyyy/mm/dd"

private:
    // attributes
    int year;
    int month;
    int day;
    // compute the number of days of month
    static int num_days(int year, int month);
    // helper function to parse date string
    static bool parse_date(const std::string& year_month_day, int& year, int& month, int& day);
};

Date::Date() : year(1), month(1), day(1) {}

Date::Date(int year, int month, int day) {
    if (year >= 1 && year <= 9999 && month >= 1 && month <= 12 && day >= 1 && day <= num_days(year, month)) {
        this->year = year;
        this->month = month;
        this->day = day;
    } else {
        this->year = this->month = this->day = 0;
    }
}

Date::Date(const std::string& year_month_day) {
    int y, m, d;
    if (parse_date(year_month_day, y, m, d)) {
        year = y;
        month = m;
        day = d;
    } else {
        year = month = day = 0;
    }
}

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

bool Date::is_valid() const {
    return !(year == 0 || month == 0 || day == 0);
}

int Date::num_days(int year, int month) {
    int n_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
        return 29;
    return n_days[month - 1];
}

bool Date::parse_date(const std::string& year_month_day, int& year, int& month, int& day) {
    std::istringstream iss(year_month_day);
    char separator;
    if (!(iss >> year >> separator >> month >> separator >> day) || separator != '/'
            || year < 1 || year > 9999 || month < 1 || month > 12 || day < 1 || day > num_days(year, month)) {
        return false;
    }
    return true;
}

int main() {
    Date d1; d1.write(); std::cout << (d1.is_valid() ? "" : "-invalid") << std::endl;
    Date d2(2022, 4, 31); d2.write(); std::cout << (d2.is_valid() ? "" : "-invalid") << std::endl;
    Date d3("2ooo/2/28"); d3.write(); std::cout << (d3.is_valid() ? "" : "-invalid") << std::endl;
    Date d4("1900/1/1"); d4.write(); std::cout << (d4.is_valid() ? "" : "-invalid") << std::endl;
    Date d5("2022#12#31"); d5.write(); std::cout << (d5.is_valid() ? "" : "-invalid") << std::endl;
    return 0;
}
