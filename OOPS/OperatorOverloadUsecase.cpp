#include<iostream>
using namespace std;
#include "OperatorOverload.cpp"

int main(){
    /*Fraction f1(10,2);
    Fraction f2(15,4);
*/
// += operator
int i = 5 ,j = 3;
(i+=j) +=j;// nested operator we use reference fraction
cout << i << j << endl;
Fraction f1(10,3);
Fraction f2(5,2);

(f1 += f2)+=f2;
f1.print();
f2.print();

        /*
        // post increment
        Fraction f3 = f1++;
        f3.print();
        f1.print();
        */

/*
// nested pre-increment
f1.print();
Fraction f3 = ++(++f1);
f1.print();
f3.print();
*/

    /*   
    f1.print();
    Fraction f3 = ++(++f1);
    f1.print();
    f3.print();
    */

/* 
f1.print();
++(++f1);
f1.print();
*/

    /*
    f1.print();
    ++f1;
    f1.print();  
    */

        /*
        // pre-increment
        Fraction f3 = ++f1;
        f3.print(); 
        f1.print();  
        */

    /*
    // add operator
     Fraction f3 = f2.add(f1);
     Fraction f4 = f1 + f2;
     f1.print();
     f2.print();
     f3.print();
     f4.print();
    */
}