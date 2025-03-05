#include<iostream>
#include <vector>
using namespace std;

//Lamda using predicate
void print_if(vector<int> nums, bool (*predicate)(int)){
    for(int i: nums)
        if(predicate(i))
            cout<<i<<" ";
}
int main(){
    vector<int> nums {1,2,3};

    print_if(nums,[] (auto x) {return x%2 == 0;});
    print_if(nums,[] (auto x) {return x%2 != 0;});

    return 0;
}