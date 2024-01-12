#include<stdio.h>
#include "student.cpp"
#include <iostream>
using namespace std;

int main()
{
    // create obj statically 

student s1;
student s2;
student s3,s4,s5;

//s1.age=24;
s1.rollno=101;

cout<< "s1 Age:" << s1.getAge() << endl;
cout << "s1 rollno:" << s1.rollno << endl;

s1.display();
s2.display();



//s2.age=11;
s2.rollno=30;


// create obj dynamically

student *s6 = new student;
//(*s6).age=23;
(*s6).rollno=104;




//cout<< s3->getAge << endl;
cout<< "s6 Age:" <<(*s6).getAge() << endl;

(*s6).rollno=13;
//cout << "s6 rollno:" << (*s6).rollno << endl;
(*s6).display();


}
