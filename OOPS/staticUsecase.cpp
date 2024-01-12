#include<iostream>
using namespace std;
#include"staticClass.cpp"

//  int main(){
// student s1(201,11);
// cout <<"rollno: " <<  s1.rollno << endl;
// cout<<"Age :" << s1.age << endl;
// cout << student:: totalstudent << endl;
// }
//static data 
int main(){
     student s1;
     student s2,s3,s4,s5;
     cout<< student::totalstudent << endl;
     cout<< student::gettotalstudent() << endl;//by using static fun/data it is not dependent to obj
     //when obj want totalstudent it will get from static class
}

//static function