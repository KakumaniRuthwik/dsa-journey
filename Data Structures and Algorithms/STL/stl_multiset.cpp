#include<iostream>
#include<set>
using namespace std;

void learnMultiSet() {
    multiset<int> ms;

    // Inserting elements (allows duplicates)
    ms.insert(10);
    ms.insert(20);
    ms.insert(10);
    ms.insert(30);
    ms.insert(20);

    cout << "Multiset (allows duplicates, sorted): ";
    for (int x : ms) cout << x << " ";
    cout << endl; // Output: 10 10 20 20 30

    // Count how many times a value appears
    cout << "Count of 10: " << ms.count(10) << endl; // 2
    cout << "Count of 40: " << ms.count(40) << endl; // 0

    // Erase: removes **all** copies of 10
    ms.erase(10);
    cout << "After erase(10): ";
    for (int x : ms) cout << x << " ";
    cout << endl;

    // Insert again for partial erase
    ms.insert(10);
    ms.insert(10); // multiset now: 10 10 20 20 30

    // Erase just one copy using iterator
    auto it = ms.find(10); // finds one 10
    if (it != ms.end()) ms.erase(it); // only 1 deleted

    cout << "After erasing one 10: ";
    for (int x : ms) cout << x << " ";
    cout << endl;

    // Lower and Upper Bound
    auto lb = ms.lower_bound(20); // first element ≥ 20
    auto ub = ms.upper_bound(20); // first element > 20

    cout << "Lower bound of 20: " << (lb != ms.end() ? to_string(*lb) : "not found") << endl;
    cout << "Upper bound of 20: " << (ub != ms.end() ? to_string(*ub) : "not found") << endl;

    // Clear all
    ms.clear();
    cout << "After clear(): size = " << ms.size() << endl;
}

int main() {
    learnMultiSet();
    return 0;
}