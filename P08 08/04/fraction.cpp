#include <iostream>
#include <cmath>

class Fraction {
public:
    // Constructors
    Fraction() : num(0), denom(1) {}
    Fraction(int numerator, int denominator);
    
    // Accessors
    int numerator() const { return num; }
    int denominator() const { return denom; }
    
    // Arithmetic operations
    Fraction sum(const Fraction& right) const;
    Fraction sub(const Fraction& right) const;
    Fraction mul(const Fraction& right) const;
    Fraction div(const Fraction& right) const;

    // Helper functions
    static int gcd(int a, int b);
    static void normalise(int& numerator, int& denominator);
    void write() const;

private:
    int num; // Numerator
    int denom; // Denominator
};

// Constructors
Fraction::Fraction(int numerator, int denominator) {
    if (denominator == 0) {
        std::cerr << "Error: Denominator cannot be zero." << std::endl;
        exit(1);
    }
    num = numerator;
    denom = denominator;
    normalise(num, denom);
}

// Arithmetic operations
Fraction Fraction::sum(const Fraction& right) const {
    int new_num = num * right.denom + right.num * denom;
    int new_denom = denom * right.denom;
    normalise(new_num, new_denom);
    return Fraction(new_num, new_denom);
}

Fraction Fraction::sub(const Fraction& right) const {
    int new_num = num * right.denom - right.num * denom;
    int new_denom = denom * right.denom;
    normalise(new_num, new_denom);
    return Fraction(new_num, new_denom);
}

Fraction Fraction::mul(const Fraction& right) const {
    int new_num = num * right.num;
    int new_denom = denom * right.denom;
    normalise(new_num, new_denom);
    return Fraction(new_num, new_denom);
}

Fraction Fraction::div(const Fraction& right) const {
    int new_num = num * right.denom;
    int new_denom = denom * right.num;
    normalise(new_num, new_denom);
    return Fraction(new_num, new_denom);
}

// Helper functions
int Fraction::gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void Fraction::normalise(int& numerator, int& denominator) {
    int common = gcd(std::abs(numerator), std::abs(denominator));
    numerator /= common;
    denominator /= common;
    if (denominator < 0) {
        numerator = -numerator;
        denominator = std::abs(denominator);
    }
}

void Fraction::write() const {
    std::cout << num << "/" << denom;
}

int main() {
    { Fraction().sum({2, 4}).write(); std::cout << ' ';
      Fraction(1,1).sum({2, 4}).write(); std::cout << ' ';
      Fraction(2,4).sum({3, 9}).write(); std::cout << ' ';
      Fraction(-2,4).sum({1, 2}).write(); std::cout << ' ';
      Fraction(3,27).sum({-27, 81}).write(); std::cout << '\n'; }
    
    { Fraction().sub({2, 4}).write(); std::cout << ' ';
      Fraction(1,1).sub({2, 4}).write(); std::cout << ' ';
      Fraction(2,4).sub({3, 9}).write(); std::cout << ' ';
      Fraction(-2,4).sub({1, 2}).write(); std::cout << ' ';
      Fraction(3,27).sub({-27, 81}).write(); std::cout << '\n'; }
    
    { Fraction().mul({2, 4}).write(); std::cout << ' ';
      Fraction(1,1).mul({2, 4}).write(); std::cout << ' ';
      Fraction(2,4).mul({3, 9}).write(); std::cout << ' ';
      Fraction(-2,4).mul({1, 2}).write(); std::cout << ' ';
      Fraction(3,27).mul({-27, 81}).write(); std::cout << '\n'; }
    
    { Fraction().div({2, 4}).write(); std::cout << ' ';
      Fraction(1,1).div({2, 4}).write(); std::cout << ' ';
      Fraction(2,4).div({3, 9}).write(); std::cout << ' ';
      Fraction(-2,4).div({1, 2}).write(); std::cout << ' ';
      Fraction(3,27).div({-27, 81}).write(); std::cout << '\n'; }
      
    return 0;
}
