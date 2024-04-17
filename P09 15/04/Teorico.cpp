#include <iostream>

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
}