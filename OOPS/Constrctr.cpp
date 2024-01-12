#include "student.cpp"
#include<stdio.h>
using namespace std;
int main(){

student s1(10,20);
cout<< "Address of s1:"<<&s1<<endl;
s1.display();
/*
student s1;
student s2;
student (*s3) = new student;
s1.display();
s2.display();
(*s3).display();

student s4(20);
s4.display();

student (*s5) = new student(101);
(*s5).display();


student s6(20,1002);
s6.display();

student (*s7)=new student(20,101);
(*s7).display();
*/
};


//only one constrctr will be called either default or 
//parameterized that too at the time of creation.class name is same of constructor name.
// no return
//no argument

