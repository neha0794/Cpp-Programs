class student{
    public:
    int age;
    int rollno;
    static int totalstudent;
student(){
    totalstudent++;
}
student(int rollno,int age){
    this->rollno=rollno;
    this->age=age;
}
int getrollno(){
    return rollno;
}
static int gettotalstudent(){
    return totalstudent;
}
  };
int student :: totalstudent=0;
