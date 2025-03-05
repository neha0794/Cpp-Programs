#include<iostream>
using namespace std;

int main(){
int x=100;
//lamda captured by value - mutable
auto I = [x]()mutable{
    x += 100;
    cout<<x<<endl;
};
I();
cout<<x<<endl;
I();
cout<<x<<endl;
    return 0;

}