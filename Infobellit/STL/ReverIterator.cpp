#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v {1,2,3,4};
    vector<int> :: reverse_iterator it = v.rbegin();
    while(it != v.rend()){
        cout<<*it<<endl;
        ++it;
    }
}