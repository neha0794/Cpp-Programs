#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> pq;

public:
    // Constructor
    PriorityQueue() {}

    bool isEmpty() {
        return pq.size() == 0;
    }

    int getSize() {
        return pq.size();
    }

    int getMin() {
        if (isEmpty()) {
            return 0; // Ideally, throw an exception
        }
        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);
        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) { // Corrected variable name
                swap(pq[childIndex], pq[parentIndex]);
            } else {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int removeMin() {
        if (isEmpty()) {
            return 0; // Ideally, throw an exception
        }

        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int parentIndex = 0;
        
        while (true) {
            int leftChildIndex = 2 * parentIndex + 1;
            int rightChildIndex = 2 * parentIndex + 2;
            int minIndex = parentIndex;

            if (leftChildIndex < pq.size() && pq[leftChildIndex] < pq[minIndex]) {
                minIndex = leftChildIndex;
            }

            if (rightChildIndex < pq.size() && pq[rightChildIndex] < pq[minIndex]) {
                minIndex = rightChildIndex;
            }

            if (minIndex == parentIndex) {
                break;
            }

            swap(pq[parentIndex], pq[minIndex]);
            parentIndex = minIndex;
        }

        return ans;
    }
};

int main() {
    PriorityQueue pq;
    pq.insert(100);
    pq.insert(10);
    pq.insert(15);
    pq.insert(4);
    pq.insert(17);
    pq.insert(21);
    pq.insert(67);
    


    cout << "Minimum element: " << pq.getMin() << endl;
    cout << "Removing min: " << pq.removeMin() << endl;
    cout << "New min: " << pq.getMin() << endl;
    while(!pq.isEmpty()){
        cout<<pq.removeMin()<<endl;
    }

    return 0;
}
