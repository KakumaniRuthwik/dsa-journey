#include<iostream>
#include<list>
using namespace std;

void learnList() {
    // Declare and initialize list
    list<int> l = {1, 2, 3};
    cout << "Initial List: ";
    for (int x : l) cout << x << " ";
    cout << endl;

    // Insert at front
    l.push_front(0); // list: 0 1 2 3
    cout << "After push_front(0): ";
    for (int x : l) cout << x << " ";
    cout << endl;

    // Insert at back
    l.push_back(4); // list: 0 1 2 3 4
    cout << "After push_back(4): ";
    for (int x : l) cout << x << " ";
    cout << endl;

    // Remove front
    l.pop_front(); // list: 1 2 3 4
    cout << "After pop_front(): ";
    for (int x : l) cout << x << " ";
    cout << endl;

    // Remove back
    l.pop_back(); // list: 1 2 3
    cout << "After pop_back(): ";
    for (int x : l) cout << x << " ";
    cout << endl;

    // Insert at position (say before 2)
    auto it = l.begin();
    advance(it, 1); // pointing to 2nd element (i.e., 2)
    l.insert(it, 99); // list: 1 99 2 3
    cout << "After insert before 2: ";
    for (int x : l) cout << x << " ";
    cout << endl;

    // Erase element at 2nd index (i.e., 2)
    it = l.begin();
    advance(it, 2); // pointing to 2
    l.erase(it); // list: 1 99 3
    cout << "After erase of 2: ";
    for (int x : l) cout << x << " ";
    cout << endl;

    // Reverse the list
    l.reverse(); // list: 3 99 1
    cout << "After reverse(): ";
    for (int x : l) cout << x << " ";
    cout << endl;

    // Clear the list
    l.clear();
    cout << "After clear(): ";
    for (int x : l) cout << x << " ";
    cout << "(size = " << l.size() << ")" << endl;
}

int main() {
    learnList();
    return 0;
}