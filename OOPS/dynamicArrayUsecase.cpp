#include<iostream>
using namespace std;

#include "dynamicArray.cpp"

int main(){
DynamicArray d1;

d1.add(10);
d1.add(20);
d1.add(30);
d1.add(40);
d1.add(50);

d1.print();

/*

//copy constructor
DynamicArray d2(d1);
d1.add(0,100);
d2.print();
*/


///*
// copy assignment operator
DynamicArray d3;
d3=d1;
d1.add(0,100);
d3.print();
//*/
}