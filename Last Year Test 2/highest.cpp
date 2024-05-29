#include <map>
#include <list>
#include <string>
#include <iostream>
#include <climits>

using namespace std;

string student_highest_avg(const map<string, list<int>> m) {
  string best_student;
  double highest_avg = 0;
  for (auto s : m)
  {
    int total = 0;
    int count = 0;
    for (int val : s.second)
    {
      total += val;
      count++;
    }
    double student_avg = (double)total / count;
    if (student_avg > highest_avg)
    {
      highest_avg = student_avg;
      best_student = s.first;
    }
  }
  return best_student;
}

int main() {
  // public tests (1 point each)
  {
    map<string, list<int>> m1 = {
        {"Jerry", {10, 20, 15}}};
    cout << student_highest_avg(m1) << endl;
  } // -> Jerry
  {
    map<string, list<int>> m2 = {
        {"Elaine", {15, 18, 14, 16}}, {"Newman", {18, 12, 19}}};
    cout << student_highest_avg(m2) << endl;
  } // -> Newman
  {
    map<string, list<int>> m3 = {
        {"Whatley", {10, 10}}, {"Kramer", {11, 12, 14}}, {"Cosmo", { 15, 10, 13}}};
    cout << student_highest_avg(m3) << endl;
  } // -> Cosmo
  {
    map<string, list<int>> m4 = {
        {"Costanza", {0, 11}}, {"Frank", {8, 12}}};
    cout << student_highest_avg(m4) << endl;
  } // -> Frank
  {
    map<string, list<int>> m5 = {
        {"Costanza", {10, 15}}, {"Frank", {10, 14}}};
    cout << student_highest_avg(m5) << endl;
  } // -> Costanza
  cout << endl;
  // private tests (1000 points each)
  {
    map<string, list<int>> m6 = {
        {"s61", {2}}, {"s62", {1, 2}}};
    cout << student_highest_avg(m6) << endl;
  } // -> s61
  {
    map<string, list<int>> m7 = {
        {"s61", {20, 2, 2}}, {"s62", {1, 1, 1, 1, 1, 1, 1, 3}}};
    cout << student_highest_avg(m7) << endl;
  } // -> s61
  {
    map<string, list<int>> m8 = {
        {"s61", {10, 11}}, {"s62", {16, 18, 19}}, {"s63", {20, 19}}};
    cout << student_highest_avg(m8) << endl;
  } // -> s63
  {
    map<string, list<int>> m9 = {
        {"s61", {1, 1}}, {"s62", {3}}, {"s63", {2}}};
    cout << student_highest_avg(m9) << endl;
  } // -> s62
  {
    map<string, list<int>> m10 = {
        {"s61", {19, 20}}, {"s62", {19, 19, 20}}, {"s63", {19, 19}}, {"s64", {19, 20, 20}}};
    cout << student_highest_avg(m10) << endl;
  } // -> s64
  
  return 0;
}