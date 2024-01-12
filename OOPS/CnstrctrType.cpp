#include<stdio.h>
#include<iostream>
using namespace std;
#include "student.cpp"

int main(){

student s1; //default cnstrctr
student s2(10); // parameter constrct
student s3(10,20); //
student s1(s2); 
s1=s2 //copy assignment operator 

};