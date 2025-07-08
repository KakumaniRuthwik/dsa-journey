#include<iostream>
#include<set>
using namespace std;

void learnSet() {
    set<int> s;

    // Insertion (only unique values stored)
    s.insert(10);
    s.insert(5);
    s.insert(20);
    s.insert(10); // Duplicate, won't be inserted

    cout << "Set after insertions (sorted): ";
    for (int x : s) cout << x << " ";
    cout << endl;

    // Searching
    if (s.find(10) != s.end()) {
        cout << "10 found in set" << endl;
    } else {
        cout << "10 not found" << endl;
    }

    if (s.count(30)) {
        cout << "30 found in set" << endl;
    } else {
        cout << "30 not found" << endl;
    }

    // Erasing element
    s.erase(5); // removes 5

    cout << "After erase(5): ";
    for (int x : s) cout << x << " ";
    cout << endl;

    // Size and Empty check
    cout << "Size: " << s.size() << endl;
    cout << "Is empty? " << (s.empty() ? "Yes" : "No") << endl;

    auto lb = s.lower_bound(25); // first element >= 25 → 30
    if (lb != s.end()) cout << "Lower bound of 25: " << *lb << endl;
    else cout << "Lower bound of 25 not found" << endl;

    // Upper Bound
    auto ub = s.upper_bound(30); // first element > 30 → 40
    if (ub != s.end()) cout << "Upper bound of 30: " << *ub << endl;
    else cout << "Upper bound of 30 not found" << endl;

    // Clearing the set
    s.clear();
    cout << "After clear(), size: " << s.size() << endl;
}
    
int main() {
    learnSet();
    return 0;
}