#include<iostream>
using namespace std;
class student {
private:
int age;

public:
int rollno;

public:
~student() {
  cout <<"Destructor called:" <<endl;
}
//default construtor
student(){
  cout << "constructor called" << endl;
}

//parameterize constructor
student(int rollno){

cout<<"constructer called 2" <<endl;
 this -> rollno=rollno;
}
student(int age,int rollno){
  cout <<"this:"<< this <<endl;
  cout <<"constrctr called 3" <<endl;
  this-> age=age;
  this-> rollno=rollno;
}

void display() { 
   cout << age << " " << rollno << endl;
}
int getAge() {
  return age;
}

int setAge(int a) {
  //if (password!=1234)
 //  return;
    
  //if (a<0)
  //return; 
   age=a;

}

};