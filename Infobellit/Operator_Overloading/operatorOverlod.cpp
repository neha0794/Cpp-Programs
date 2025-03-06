#include <iostream>
#include <algorithm> // For __gcd
using namespace std;

class Fraction {
public:
    int numerator;
    int denominator;

    // Constructor
    Fraction(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
        simplify(); // Ensures the fraction is always in its simplest form
    }

    // Function to simplify the fraction
    void simplify() {
        int gcd = __gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

    // Function to print the fraction
    void print() {
        cout << numerator << "/" << denominator << endl;
    }

    // Operator overloading for addition
    Fraction operator+(const Fraction &f2) {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;
        int num = x * numerator + y * f2.numerator;

        return Fraction(num, lcm);
    }

    // Operator overloading for multiplication
    Fraction operator*(const Fraction &f2) {
        int mul_num = numerator * f2.numerator;
        int mul_deno = denominator * f2.denominator;

        return Fraction(mul_num, mul_deno);
    }

    // Pre-increment operator (++f)
    Fraction& operator++() {
        numerator = numerator + denominator;
        simplify();
        return *this;
    }

    // Post-increment operator (f++)
    Fraction operator++(int) {
        Fraction temp(numerator, denominator); // Save current state
        numerator = numerator + denominator;
        simplify();
        return temp; // Return old state
    }
};

int main() {
    Fraction f1(2, 4);
    Fraction f2(3, 6);

    cout << "f1: ";
    f1.print();
    cout << "f2: ";
    f2.print();

    // Addition
    Fraction f3 = f1 + f2;
    cout << "f1 + f2: ";
    f3.print();

    // Multiplication
    Fraction f4 = f1 * f2;
    cout << "f1 * f2: ";
    f4.print();

    // Pre-increment
    ++f1;
    cout << "After pre-increment (++f1): ";
    f1.print();

    // Post-increment
    Fraction f5 = f1++;
    cout << "After post-increment (f1++), original f1: ";
    f5.print();
    cout << "After post-increment (f1++), new f1: ";
    f1.print();

    return 0;
}
