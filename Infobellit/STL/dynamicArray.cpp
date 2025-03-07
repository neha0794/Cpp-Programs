#include <iostream>
using namespace std;

class DynamicArray {
private:
    int *data;
    int nxtIdx;
    int capacity;

public:
    DynamicArray() {
        this->nxtIdx = 0;
        this->capacity = 4;
        this->data = new int[capacity];
    }

    void push_back(int element) {
        if (nxtIdx != capacity) {
            data[nxtIdx] = element;
            nxtIdx++;
        } else {
            this->capacity *= 2;
            int *new_arr = new int[capacity];
            for (int i = 0; i < nxtIdx; i++) {
                new_arr[i] = data[i];
            }
            delete[] data;
            this->data = new_arr;
            data[nxtIdx] = element;
            nxtIdx++;
        }
    }

    void print() {
        for (int i = 0; i < nxtIdx; i++) {
            cout << this->data[i] << " ";
        }
        cout << endl;
    }

    // Overload the << operator
    friend ostream &operator<<(ostream &out, const DynamicArray &arr);
};

// Definition of overloaded << operator
ostream &operator<<(ostream &out, const DynamicArray &arr) {
    // out << "[ ";
    for (int i = 0; i < arr.nxtIdx; i++) {
        out << arr.data[i] << " ";
    }
    // out << "]";
    return out;
}

int main() {
    DynamicArray arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);
    arr.push_back(50);

    arr.print();  // Using print() method
    cout << arr << endl;  // Using overloaded << operator

    return 0;
}
