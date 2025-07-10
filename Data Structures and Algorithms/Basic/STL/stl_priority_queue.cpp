#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void learnPriorityQueue() {
    // Default: Max-heap (largest element at top)
    priority_queue<int> maxHeap;

    maxHeap.push(30);
    maxHeap.push(10);
    maxHeap.push(50);
    maxHeap.push(20);

    cout << "Max-Heap Top: " << maxHeap.top() << endl; // 50

    cout << "Max-Heap Elements (descending): ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;

    // Min-Heap using greater<>
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(30);
    minHeap.push(10);
    minHeap.push(50);
    minHeap.push(20);

    cout << "Min-Heap Top: " << minHeap.top() << endl; // 10

    cout << "Min-Heap Elements (ascending): ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
}
    
int main() {
    learnPriorityQueue();
    return 0;
}