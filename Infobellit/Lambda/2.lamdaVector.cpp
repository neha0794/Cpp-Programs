#include<iostream>
#include<vector>
using namespace std;


int main(){
vector<int> test_score {93,88,75,68,65};
auto bonus = [] (vector<int> &score,int bonus_point){
    for(int &score : score){
    score += bonus_point;
    }
};
bonus(test_score,5);
    for(int score : test_score){
        cout<<score<<endl;
    }


}