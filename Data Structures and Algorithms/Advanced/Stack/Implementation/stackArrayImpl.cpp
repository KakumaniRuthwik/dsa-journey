#include<iostream>
using namespace std;

class ArrayStack{
private :

    int* stackArray;
    int capacity;
    int topIndex;

public :
    
    // Constructor to initialize stack with a given size
    ArrayStack(int size = 10){
        capacity = size;
        stackArray = new int[capacity];
        topIndex = -1;
    }

    // Destructor to free allocated memory
    ~ArrayStack() {
        delete[] stackArray;
    }

    // Push operation: adds element to top of stack
    void push(int data){
        if(topIndex >= capacity - 1 ){
            cout << "Stack Overflow" << endl;
            return;
        }

        stackArray[++topIndex] = data;
    }

    // Pop operation: removes and returns top element
    int pop(){
        if(isEmpty()){
            cout << "Stack Underflow" << endl;
            return -1;
        }

        return stackArray[topIndex--];
    }

    // Returns the top element without removing it
    int top(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
            return -1;
        }

        return stackArray[topIndex];
    }

    // checks if the stack is empty
    bool isEmpty(){
        return topIndex == -1;
    }
};

int main() {
    ArrayStack s(5);  // stack of capacity 5

    cout << "Pushing elements..." << endl;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    s.push(60);

    cout << "\nTop element: " << s.top() << endl;

    cout << "\nPopping elements..." << endl;
    cout << s.pop() << endl;  
    cout << s.pop() << endl;  
    cout << s.pop() << endl;  

    cout << "\nTop element now: " << s.top() << endl;

    cout << "\nChecking if empty: " << (s.isEmpty() ? "Yes" : "No") << endl;

    cout << "\nPopping remaining..." << endl;
    cout << s.pop() << endl;  
    cout << s.pop() << endl;  

    cout << s.pop() << endl;

    cout << "\nIs stack empty: " << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
