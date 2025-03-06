#include<iostream>
#include<memory>
using namespace std;

class rectangle{
    public:
        int l;
        int b;

        rectangle(int l,int b){
            this->l = l;
            this->b = b;
        }
        int area(){
            return l*b;
        }
};
int main(){
    
    unique_ptr<rectangle> r1(new rectangle(2,4));
    cout<<r1->area()<<endl;
    
    unique_ptr<rectangle> r2;
   
    // Transfer ownership from r1 to r2 using move
    r2 = move(r1);
    // Now r1 is nullptr, accessing it would cause an error
    // Print the area using r2
    cout<<r2->area()<<endl;
    

return 0;
}
