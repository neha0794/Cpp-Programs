#include <iostream> 
using namespace std;
#include "student.cpp"


int main(){
// copy assignment "=" by this we can copy constrctr more than one time    
student s1(10,20);
student s2(60,30);
student (*s3) = new student(40,50);
s2 = s1;
s2 = (*s3);
(*s3) = s2;
s1.display();
s2.display();
(*s3).display();
    /*
    student s1(20,1001);
    cout<<"s2:";
    s1.display();

    student s2(s1);
    cout<<"s2:";
    s2.display();
//wrong output
student (*s3) = new student(20,2001);
cout<<"s3:";
(*s3).display();

student s4(*s3);
cout<<"s4:";
(s4).display();

student (*s5)= new student(*s3);
student (*s6)= new student(s1);
*/
}