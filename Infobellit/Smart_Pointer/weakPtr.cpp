#include<iostream>
#include<memory>
using namespace std;


class B;
class A{
    shared_ptr<B> b_ptr;
    int b;
    public:
    void set_B(shared_ptr<B> &b){
        b_ptr = b;

    }
    int set_b(int b){
        this->b=b;
    return 0;
    }
        A(){
            cout<<"constructor"<<endl;
        }
        ~A(){
            cout<<"destructor"<<endl;
        }
};
class B{
    weak_ptr<A> a_ptr; // Changed to weak_ptr to avoid circular reference
    int a;
    public:
        void set_A(shared_ptr<A> &a){
            a_ptr = a;
        }
        int set_a(int a){
            this->a = a;
    return 0;
        }
        B(){
            cout<<"constructor"<<endl;
        }
        ~B(){
            cout<<"destructor"<<endl;
        }
};
int main(){

    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();
    a->set_B(b);
    b->set_A(a);
    a->set_b(20);
    b->set_a(10);


    return 0;
}