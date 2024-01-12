class student{
public:
int age;
const int rollno;
student(int age,int r) : rollno(r),age(age){

}
void display(){
    cout << "age:"<<age <<""<<"rollno:"<< rollno << endl;
}

};