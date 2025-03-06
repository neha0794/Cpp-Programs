#include <iostream>
#include <memory>
using namespace std;

class B; // Forward declaration of class B

class A {
    shared_ptr<B> b_ptr; // Shared ownership of B
    int b;
public:
    void set_B(shared_ptr<B> b) {
        b_ptr = b; // Assign shared_ptr
    }
    
    void set_b(int b) {
        this->b = b;
    }

    A() {
        cout << "A constructor" << endl;
    }

    ~A() {
        cout << "A destructor" << endl;
    }
};

class B {
    shared_ptr<A> a_ptr; // Shared ownership of A
    int a;
public:
    void set_A(shared_ptr<A> a) {
        a_ptr = a; // Assign shared_ptr
    }

    void set_a(int a) {
        this->a = a;
    }

    B() {
        cout << "B constructor" << endl;
    }

    ~B() {
        cout << "B destructor" << endl;
    }
};

int main() {
    shared_ptr<A> a = make_shared<A>(); // Creating shared_ptr for A
    shared_ptr<B> b = make_shared<B>(); // Creating shared_ptr for B

    a->set_B(b);
    b->set_A(a);

    a->set_b(20);
    b->set_a(10);

    return 0;
}
