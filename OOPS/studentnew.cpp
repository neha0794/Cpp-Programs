#include "student.cpp"

int main(){ //setter

student s1;
student (*s2) = new student;

s1.setAge(20);
s2->setAge(24);

s1.display();
(*s2).display();

};