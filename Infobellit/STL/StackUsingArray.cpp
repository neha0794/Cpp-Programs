#include <iostream>
#include <climits>
using namespace std;

class stackUsingArray {
    int *data;
    int nextIndex;
    int capacity;

public:
    // Constructor with dynamic memory allocation
    stackUsingArray(int totalSize) {
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
    }

    // Return size of stack
    int size() {
        return nextIndex;
    }

    // Check if stack is empty
    bool isempty() {
        return nextIndex == 0;
    }

    // Push element to stack (dynamically resize if needed)
    void push(int element) {
        if (nextIndex == capacity) {
            int *newData = new int[2 * capacity];
            for (int i = 0; i < capacity; i++) {
                newData[i] = data[i];
            }
            delete[] data; // Free old memory
            data = newData;
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    // Pop element from stack
    int pop() {
        if (isempty()) {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        nextIndex--; // Decrement index before returning value
        return data[nextIndex];
    }

    // Get top element of stack
    int top() {
        if (isempty()) {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1]; // Get top element
    }

    // Destructor to release memory
    ~stackUsingArray() {
        delete[] data;
    }
};

int main() {
    stackUsingArray s(5); // Provide an initial size
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "Top element: " << s.top() << endl;
    cout << "Popped element: " << s.pop() << endl;
    cout << "Popped element: " << s.pop() << endl;

    return 0;
}
