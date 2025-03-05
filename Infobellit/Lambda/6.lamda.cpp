//statefull lamda
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int x=100;
    auto I = [x]();
    x += 100;
    cout<<x<<endl;

return 0;
}