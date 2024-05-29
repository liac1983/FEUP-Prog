#include "Receipt.h"
#include <iostream>
#include <iomanip>
using namespace std;

Receipt::Receipt(int nif) : nif_(nif) { 
  
}

int Receipt::get_nif() const { 
  return nif_; 
}

void Receipt::add(const product& prod) { 
  products_.push_back(prod); 
}

float Receipt::total_price() const {
  float total_price = 0;
  for (auto p : products_) {
    total_price += p.price * (100 + p.tax) / 100.0;
  }
  return total_price;
}

int Receipt::count_zero_tax() const {
  int count = 0;
  for (auto p : products_) {
    if (p.tax == 0) { 
      count++; 
    }
  }
  return count;
}

int main() {
  // public tests (1 point each)
  {
    Receipt r(123456789);
    print(r);
  } // -> 123456789 0 0.00 
  {
    Receipt r(221834835);
    r.add({"Tofu", 10.0, 16}); 
    print(r);
  } // -> 221834835 0 11.60
  {
    Receipt r(221834835);
    r.add({"Tofu", 10.0, 16}); r.add({"Eggs", 10.0, 0}); r.add({"Beans", 10.0, 0});
    print(r);
  } // -> 221834835 2 31.60
  {
    Receipt r(217234920);
    r.add({"Meat", 3.84, 0}); r.add({"Milk", 0.92, 0}); r.add({"Milk", 0.92, 0});
    print(r);
  } // -> 221834835 2 31.60
  {
    Receipt r(217234920);
    r.add({"Meat", 3.84, 100}); r.add({"Milk", 0.92, 13}); 
    r.add({"Milk", 0.92, 21}); r.add({"Sausage", 2.17, 6});
    print(r);
  } // -> 217234920 0 9.83
  cout << endl;
  // private tests (1000 points each)
  {
    Receipt r(123456789);
    r.add({"Tofu", 10.0, 0}); 
    print(r);
  } // -> 123456789 1 10.00
  {
    Receipt r(221834835);
    r.add({"Tofu", 10.0, 0}); r.add({"Eggs", 10.0, 16}); r.add({"Beans", 10.0, 23});
    print(r);
  } // -> 221834835 1 33.90
  {
    Receipt r(9999999);
    r.add({"Meat", 9.84, 0}); r.add({"Milk", 1.92, 0}); r.add({"Milk", 1.92, 0});
    print(r);
  } // -> 9999999 3 13.68
  {
    Receipt r(217234920);
    r.add({"Meat", 3.84, 16}); r.add({"Milk", 1.92, 13}); r.add({"Beans", 0.92, 6});
    print(r);
  } // -> 217234920 0 7.60
  {
    Receipt r(123123123);
    r.add({"Meat", 10, 100}); r.add({"Milk", 1.92, 99}); r.add({"Beans", 0.92, 16});
    r.add({"Sausage", 1.92, 16}); r.add({"Beef", 5.23, 0}); r.add({"Ferrari", 5.92, 100});
    print(r);
  } // -> 123123123 1 44.19

  return 0;
}