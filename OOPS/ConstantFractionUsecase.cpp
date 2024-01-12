#include<iostream>
using namespace std;
#include "ConstantFraction.cpp"

int main(){
    Fraction f1(10,2);
    Fraction f2(15,4);

    Fraction const f3;
    cout << f3.getNumerator() << f3.getDenominator() << endl;
// f3.setNumerator(10); //set fun cant be static so it cant be constant
}
