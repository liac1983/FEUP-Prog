/*#include <iostream>

using namespace std;

template <typename T>
class Pair
{
    public:
        Pair(const T& x = 0, const T& y=0) : x_(x), y_(y) { }
        Pair<double> p4 = Pair<double>(4,5);
    private:
        T x_;
        T y_;
};

int main() {
    
    return 0;
}*/

#include <iostream>
#include <vector>
using namespace std;

class C1 {
    public:
        C1(int x = 0) : x_(x) { }
        void show() const {cout << "x_" << x_; }
    protected:
        int x_;
};

class C2 : public C1 {
    public:
        C2(int x = 0, int y = 0) : C1(x) {y_ = y; }
        void show() const { cout << "x=" << x_; cout << "y=" << y_; }
    private:
        int y_;
};

int main() {
    C1 c1(5);
    C2 c2(7,8);
    C1* pc1 = &c2;
    pc1->show();
    return 0;
}

