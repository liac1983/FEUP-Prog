#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class Date {
public:
    // constructors
    Date() : yyyymmdd("00010101") {} // Default constructor initializes with January 1, 0001

    Date(int year, int month, int day) {
        if (year >= 1 && year <= 9999 && month >= 1 && month <= 12 && day >= 1 && day <= num_days(year, month)) {
            std::ostringstream oss;
            oss << std::setw(4) << std::setfill('0') << year
                << std::setw(2) << std::setfill('0') << month
                << std::setw(2) << std::setfill('0') << day;
            yyyymmdd = oss.str();
        } else {
            yyyymmdd = "00000000";
        }
    }

    Date(const std::string& year_month_day) : yyyymmdd("00000000") {
        if (year_month_day.length() == 8 &&
            std::isdigit(year_month_day[0]) && std::isdigit(year_month_day[1]) && std::isdigit(year_month_day[2]) && std::isdigit(year_month_day[3]) &&
            std::isdigit(year_month_day[4]) && std::isdigit(year_month_day[5]) && std::isdigit(year_month_day[6]) && std::isdigit(year_month_day[7])) {
            yyyymmdd = year_month_day;
        }
    }

    // accessors
    int get_year() const { return std::stoi(yyyymmdd.substr(0, 4)); }
    int get_month() const { return std::stoi(yyyymmdd.substr(4, 2)); }
    int get_day() const { return std::stoi(yyyymmdd.substr(6, 2)); }

    // other methods
    bool is_valid() const { return yyyymmdd != "00000000"; }
    void write() const {
        std::cout << yyyymmdd.substr(0, 4) << '/' << yyyymmdd.substr(4, 2) << '/' << yyyymmdd.substr(6, 2);
    }

private:
    // compute the number of days of month
    static int num_days(int year, int month) {
        int n_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
            return 29;
        return n_days[month - 1];
    }

    // attribute
    std::string yyyymmdd;
};

int main() {
    Date d1; d1.write(); std::cout << (d1.is_valid() ? "" : "-invalid") << std::endl;
    Date d2(2022, 4, 31); d2.write(); std::cout << (d2.is_valid() ? "" : "-invalid") << std::endl;
    Date d3("2ooo/2/28"); d3.write(); std::cout << (d3.is_valid() ? "" : "-invalid") << std::endl;
    Date d4("1900/1/1"); d4.write(); std::cout << (d4.is_valid() ? "" : "-invalid") << std::endl;
    Date d5("2022#12#31"); d5.write(); std::cout << (d5.is_valid() ? "" : "-invalid") << std::endl;
    return 0;
}
