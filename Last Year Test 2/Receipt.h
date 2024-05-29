#ifndef __RECEIPT_H__
#define __RECEIPT_H__

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

struct product {
  string name;       // e.g. "Tomatoes"
  float price;       // e.g. 4.5  (> 0)
  unsigned char tax; // e.g. 23 (0 to 100)
};

class Receipt {
public:
  Receipt(int nif);
  int get_nif() const;
  void add(const product& p);
  int count_zero_tax() const;
  float total_price() const;
private:
  int nif_;
  vector<product> products_;
};


void print(const Receipt& r) {
   cout << fixed << setprecision(2) << r.get_nif() << ' ' 
        << r.count_zero_tax() << ' '  << r.total_price()  << endl;
}
#endif
