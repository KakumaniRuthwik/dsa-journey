#include<iostream>
#include<vector>
using namespace std;

class CircularQueue {
private:
    vector<int> arr;
    int front, rear, size, capacity;

public:
    CircularQueue(int cap) {
        capacity = cap;
        arr.resize(cap);
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full\n";
            return false;
        }
        rear = (rear + 1) % capacity;   // circular increment
        arr[rear] = x;
        size++;
        return true;
    }

    bool dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return false;
        }
        front = (front + 1) % capacity; // circular increment
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < size; i++) {
            int idx = (front + i) % capacity;
            cout << arr[idx] << " ";
        }
        cout << "\n";
    }
};

int main() {
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    
    q.printQueue();

    q.dequeue();
    q.dequeue();

    q.printQueue();

    q.enqueue(60);
    q.enqueue(70);

    q.printQueue();

    return 0;
}
