#include<iostream>
#include<queue>
using namespace std;

void learnQueue() {
    queue<int> q;

    // Push elements (enqueue)
    q.push(10);
    q.push(20);
    q.push(30);  // Queue: [10, 20, 30] (10 is at front)

    cout << "Front element: " << q.front() << endl; // 10
    cout << "Back element: " << q.back() << endl;   // 30

    // Pop element (dequeue)
    q.pop(); // removes 10 → Queue: [20, 30]
    cout << "After pop(), new front: " << q.front() << endl; // 20

    // Size of the queue
    cout << "Size: " << q.size() << endl;

    // Is queue empty?
    cout << "Is empty? " << (q.empty() ? "Yes" : "No") << endl;

    // Printing all elements (destructive)
    cout << "Queue content (front to back): ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    cout << "Is empty after popping all? " << (q.empty() ? "Yes" : "No") << endl;
}

int main() {
    learnQueue();
    return 0;
}