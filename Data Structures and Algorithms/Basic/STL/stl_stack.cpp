#include<iostream>
#include<stack>
using namespace std;

void learnStack() {
    stack<int> st;

    // Pushing elements
    st.push(10);
    st.push(20);
    st.push(30);  // Stack is now: [10, 20, 30] (30 is on top)

    cout << "Top element: " << st.top() << endl; // 30

    // Popping top element
    st.pop();  // removes 30
    cout << "After pop(), new top: " << st.top() << endl; // 20

    // Checking size
    cout << "Size: " << st.size() << endl; // 2

    // Is stack empty?
    cout << "Is empty? " << (st.empty() ? "Yes" : "No") << endl;

    // Printing all elements (destructive, for demo only)
    cout << "Stack content (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop(); // removes the top
    }
    cout << endl;

    cout << "Is empty after popping all? " << (st.empty() ? "Yes" : "No") << endl;
}

int main() {
    learnStack();
    return 0;
}