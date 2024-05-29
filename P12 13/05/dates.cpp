#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

class Date {
public:
  Date(int year = 1, int month = 1, int day = 1) 
    : year_(year), month_(month), day_(day) {}
  int get_year() const { return year_; }
  int get_month() const { return month_; }
  int get_day() const { return day_; }
private:
  int year_, month_, day_;
};

bool operator<(const Date& date1, const Date& date2) {
  int d1 = date1.get_year() * 10000 + date1.get_month() * 100 + date1.get_day();
  int d2 = date2.get_year() * 10000 + date2.get_month() * 100 + date2.get_day();

  return d1 < d2;
  // if (date1.get_year() < date2.get_year())
  //   return true;
  // else
  //   if (date1.get_year() == date2.get_year()) {
  //     if (date1.get_month() < date2.get_month())
  //       return true;
  //     else {
  //       if (date1.get_month() == date2.get_month())
  //         if (date1.get_day() < date2.get_day())
  //           return true;
  //     }
  //   }
  // return false;
}

ostream& operator<< (ostream& out, const Date& date) {
  const char sep = '/';
  out << setw(4) << setfill('0') << date.get_year() << sep <<
         setw(2) << setfill('0') << date.get_month() << sep <<
         setw(2) << setfill('0') << date.get_day();
  return out;
}

int main() {
  // public tests (1 point each) 
  {
    vector<Date> dates = { {2023,11,15}, {2021,12,8}, {2023,11,14} };
    sort(dates.begin(), dates.end());
    for (const auto& d : dates) cout << d << " ";
    cout << '\n';
  } // -> 2021/12/08 2023/11/14 2023/11/15
  {
    vector<Date> dates = { {2000,1,1}, {2000,2,1}, {2000,12,31} };
    sort(dates.begin(), dates.end());
    for (const auto& d : dates) cout << d << " ";
    cout << '\n';
  } // -> 2000/01/01 2000/02/01 2000/12/31 
  {
    vector<Date> dates = { {2001,10,31}, {2005,10,31}, {2010,10,31}, {1992,10,31} };
    sort(dates.begin(), dates.end());
    for (const auto& d : dates) cout << d << " ";
    cout << '\n';
  } // -> 1992/10/31 2001/10/31 2005/10/31 2010/10/31
  {
    vector<Date> dates = { {2023,4,28}, {999,1,1} };
    sort(dates.begin(), dates.end());
    for (const auto& d : dates) cout << d << " ";
    cout << '\n';
  } // -> 0999/01/01 2023/04/28
  {
    vector<Date> dates = { {2075,2,2}, {2077,10,10}, {2075,2,2}};
    sort(dates.begin(), dates.end());
    for (const auto& d : dates) cout << d << " ";
    cout << '\n';
  }  // -> 2075/02/02 2075/02/02 2077/10/10
  cout << '\n';
  // private tests (1000 points each)
  {
    vector<Date> dates = { {2023,4,29}, {2023,4,30}, {2023,4,28} };
    sort(dates.begin(), dates.end());
    for (const auto& d : dates) cout << d << " ";
    cout << '\n';
  }  // -> 2023/04/28 2023/04/29 2023/04/30 
  {
    vector<Date> dates = { {2000,12,1}, {2000,11,1}, {2000,10,31} };
    sort(dates.begin(), dates.end());
    for (const auto& d : dates) cout << d << " ";
    cout << '\n';
  } // -> 2000/10/31 2000/11/01 2000/12/01
  {
    vector<Date> dates = { {1970,9,20}, {1969,10,31}, {2099,6,30}, {1975,7,31} };
    sort(dates.begin(), dates.end());
    for (const auto& d : dates) cout << d << " ";
    cout << '\n';
  } // -> 1969/10/31 1970/09/20 1975/07/31 2099/06/30
  {
    vector<Date> dates = { {100,10,2}, {1,1,1}, {1000,1,10} };
    sort(dates.begin(), dates.end());
    for (const auto& d : dates) cout << d << " ";
    cout << '\n';
  }  // -> 0001/01/01 0100/10/02 1000/01/10
  {
    vector<Date> dates = { {2030,1,2}, {2029,1,1}};
    sort(dates.begin(), dates.end());
    for (const auto& d : dates) cout << d << " ";
    cout << '\n';
  }  // -> 2029/01/01 2030/01/02
 
  return 0;
}