#include <cstring>
class student{
int age;
char *name;

public:
student(int age,char *name){
    this->age = age;
    //this->name = name;
    //Deep copy
    this->name = new char[strlen(name) + 1];
    strcpy(this->name,name);
}
void display(){

    cout << name << " " << age << endl;
}

};