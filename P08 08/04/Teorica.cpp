#include <iostream>
using namespace std;

class C1 {
    public:
        C1(char c = 'X') : c_(c) { std::cout << "c(" << c_ << ")"; }
        void set_c(char c) { c_ = c; }
        ~C1() { std::cout << "d(" << c_ << ")"; }
    private:
        char c_;
};

int main() {
    C1 c;
    for (char c = 'A'; c < 'C'; c++) {
        C1 x(c);
    }
    c.set_c('Y');
    return 0;
}