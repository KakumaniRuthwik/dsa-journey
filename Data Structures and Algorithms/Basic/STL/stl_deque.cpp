#include<iostream>
#include<deque>
using namespace std;

void learnDeque() {
    deque<int> dq = {1, 2, 3};
    cout << "Initial Deque: ";
    for (int x : dq) cout << x << " ";
    cout << endl;

    // Add to front and back
    dq.push_front(0); // {0, 1, 2, 3}
    dq.push_back(4);  // {0, 1, 2, 3, 4}
    cout << "After push_front(0) and push_back(4): ";
    for (int x : dq) cout << x << " ";
    cout << endl;

    // Remove from front and back
    dq.pop_front(); // {1, 2, 3, 4}
    dq.pop_back();  // {1, 2, 3}
    cout << "After pop_front() and pop_back(): ";
    for (int x : dq) cout << x << " ";
    cout << endl;

    // Access using index
    cout << "Element at index 1: " << dq[1] << endl;

    // Insert at position (say index 1)
    dq.insert(dq.begin() + 1, 99); // {1, 99, 2, 3}
    cout << "After insert at index 1: ";
    for (int x : dq) cout << x << " ";
    cout << endl;

    // Erase element at index 2
    dq.erase(dq.begin() + 2); // removes 2 → {1, 99, 3}
    cout << "After erase at index 2: ";
    for (int x : dq) cout << x << " ";
    cout << endl;

    // Size of deque
    cout << "Size of deque: " << dq.size() << endl;

    // Clear deque
    dq.clear();
    cout << "After clear(): ";
    for (int x : dq) cout << x << " ";
    cout << "(size = " << dq.size() << ")" << endl;
}

int main() {
    learnDeque();
    return 0;
}