#include<iostream>
using namespace std;

class ArrayQueue{
    
private:
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Constructor: allocate array and initialize indices
    ArrayQueue(int capacity = 100){
        size = capacity;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    ~ArrayQueue() {
        delete[] arr;
        arr = nullptr;
    }

    // Check if queue is full
    bool isFull(){
        return rear == size - 1;
    }

    // Check if queue is empty
    bool isEmpty(){
        return front == -1 || front > rear;
    }

    // Insert element at rear
    void enqueue(int data){
        if(isFull()){
            cout << "Queue is Full" << endl;
            return;
        }

        if(front == -1)   // first element
            front = 0;

        rear++;
        arr[rear] = data;

        cout << "Value enqueued." << endl;
    }

    // Remove element from front
    int dequeue(){
        if(isEmpty()){
            cout << "Queue is Empty" << endl;
            return -1;
        }

        int removed = arr[front];
        front++;   // move front forward

        cout << "dequeued successfully." << endl;
        return removed;
    }

    // Return current front element
    int getFront(){
        if(isEmpty()){
            cout << "Queue is Empty." << endl;
            return -1;
        }
        return arr[front];
    }

    // Return current rear element
    int getRear(){
        if(isEmpty()){
            cout << "Queue is Empty." << endl;
            return -1;
        }
        return arr[rear];
    }

    // Number of active elements in the queue
    int getSize() {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }

    // Display all valid elements
    void display(){
        if(isEmpty()){
            cout << "Queue is Empty." << endl;
            return;
        }

        cout << "Queue : ";
        for(int i = front; i <= rear; i++){
            cout << arr[i] << ", ";
        }
        cout << endl;
    }
};


int main() {

    ArrayQueue q(5);

    q.enqueue(10); 
    q.enqueue(20); 
    q.enqueue(30); 
    q.enqueue(40); 

    
    q.display();  
    
    cout << "Front element: " << q.getFront() << endl;  
    cout << "Rear element : " << q.getRear() << endl;   

    q.dequeue();  
    q.dequeue();  

    q.display();

    cout << "Current queue size: " << q.getSize() << endl; 

    q.enqueue(50);
    q.enqueue(60); 

    q.display();  

    cout << "Final Front: " << q.getFront() << endl;
    cout << "Final Rear : " << q.getRear() << endl;

    return 0;
}
