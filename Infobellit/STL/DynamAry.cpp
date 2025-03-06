#include<iostream>
using namespace std;

class Dynamic{
    public:
        int *data;
        int capacity;
        int nextIndex;

        Dynamic(){
            data = new int[2];
            nextIndex=0;
            capacity=2;
        }
        //Adding element in array
        int add(int element){
            if(nextIndex==capacity){
                int *newData = new int[2*capacity];//Double the size if no space
                //capacity*=2;
                for(int i=0; i<nextIndex; i++){
                    newData[i]=data[i];
                }
                delete [] data;
                data = newData;
                capacity *= 2;
            }
            data[nextIndex]=element;
            nextIndex++;
        return 0;
        }
        //Finding element in ith index
        void findnum(int i){
            if(i>nextIndex){
                cout<<"Out of range"<<endl;
            }
            else{
                cout<<data[i]<<endl;
            }
        }
        void print(){
            for(int i=0; i<nextIndex; i++){
                cout<<data[i]<<" ";
            }
            cout<<endl;
        }

};
int main(){
    Dynamic d1;
    d1.add(1);
    d1.add(2);
    d1.add(3);
    d1.add(4);
    d1.print();

    return 0;
}