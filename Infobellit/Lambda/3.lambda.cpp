//Using func() as parameter
#include<iostream>
#include <vector>
#include <functional>
using namespace std;

void filter_vector(const vector<int>& nums, function<bool(int)> condition) {
    for (int num : nums) {
        if (condition(num)) {  // Apply the filtering condition
            cout << num << " ";
        }
    }
    cout << endl;
}

void test4(){
    vector<int> nums{10,20,30,40,50,60,70};
    filter_vector(nums,[](int x){return x>50;});
    filter_vector(nums,[](int x){return x<= 30;});

}
int main(){
    test4();
    return 0;
}