// Pair.h
#ifndef PAIR_H
#define PAIR_H

#include <iostream>
#include <string>

template<typename T1, typename T2>
class Pair {
public:
    Pair(const T1& first, const T2& second) : first_(first), second_(second) {}

    T1 get_first() const { return first_; }
    T2 get_second() const { return second_; }

    void show() const { std::cout << "{" << first_ << "," << second_ << "}"; }

private:
    T1 first_;
    T2 second_;
};

#endif // PAIR_H

// Pair.cpp (No implementation needed for a template class)

// External functions
#include <vector>
#include <algorithm>

template<typename T1, typename T2>
void sort_by_first(std::vector<Pair<T1, T2>>& vec) {
    std::sort(vec.begin(), vec.end(), [](const Pair<T1, T2>& a, const Pair<T1, T2>& b) {
        return a.get_first() < b.get_first();
    });
}

template<typename T1, typename T2>
void sort_by_second(std::vector<Pair<T1, T2>>& vec) {
    std::sort(vec.begin(), vec.end(), [](const Pair<T1, T2>& a, const Pair<T1, T2>& b) {
        return a.get_second() < b.get_second();
    });
}

template<typename T1, typename T2>
void show(const std::vector<Pair<T1, T2>>& vec) {
    std::cout << "{" ;
    for (const auto& pair : vec) {
        pair.show();
    }
    std::cout << "}" ;
}
