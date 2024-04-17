// Date.cpp

#include "Date.h"

Date::Date() : year_(1), month_(1), day_(1) {}

Date::Date(int year, int month, int day) : year_(year), month_(month), day_(day) {}

bool Date::is_before(const Date& date) const {
    if (year_ < date.year_) return true;
    if (year_ > date.year_) return false;
    if (month_ < date.month_) return true;
    if (month_ > date.month_) return false;
    return day_ < date.day_;
}
