#include <iostream>
#include <climits> // For INT_MIN
using namespace std;

class QueueUsingArray {
    int *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity; // Missing declaration fixed

public:
    QueueUsingArray(int s) {
        data = new int[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = s;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int element) {
        if (size == capacity) {
            cout << "Queue Full!" << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if (firstIndex == -1) {
            firstIndex = 0;
        }
        size++;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return INT_MIN; // Return error value
        }
        return data[firstIndex];
    }

    int dequeue() { // Fixed function name
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return INT_MIN;
        }
        int ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;

        if (size == 0) {
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }

    ~QueueUsingArray() { // Destructor to free memory
        delete[] data;
    }
};

// ✅ **Test the Queue**
int main() {
    QueueUsingArray q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Front element: " << q.front() << endl; // Expected: 10
    cout << "Dequeued: " << q.dequeue() << endl;    // Expected: 10
    cout << "Dequeued: " << q.dequeue() << endl;    // Expected: 20
    cout << "Front element: " << q.front() << endl; // Expected: 30

    return 0;
}
