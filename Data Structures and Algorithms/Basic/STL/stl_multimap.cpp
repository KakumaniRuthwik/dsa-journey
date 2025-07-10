#include<iostream>
#include<map>
using namespace std;

void learnMultiMap() {
    multimap<string, int> mm;

    // Inserting key-value pairs
    mm.insert({"apple", 10});
    mm.insert({"banana", 20});
    mm.insert({"apple", 15}); // duplicate key allowed
    mm.insert({"cherry", 25});
    mm.insert(make_pair("banana", 30));

    cout << "Multimap content (sorted by key):\n";
    for (auto p : mm) {
        cout << p.first << " : " << p.second << endl;
    }

    // Count how many values under a key
    cout << "Count of 'apple': " << mm.count("apple") << endl;

    // Find first occurrence of a key
    auto it = mm.find("banana");
    if (it != mm.end()) {
        cout << "First banana found: " << it->second << endl;
    }

    // Iterate all values for a specific key
    cout << "All values for 'banana': ";
    auto range = mm.equal_range("banana");
    for (auto i = range.first; i != range.second; ++i) {
        cout << i->second << " ";
    }
    cout << endl;

    // Erase all entries for a key
    mm.erase("apple");
    cout << "After erase(\"apple\"):\n";
    for (auto p : mm) {
        cout << p.first << " : " << p.second << endl;
    }

    // Clear all
    mm.clear();
    cout << "After clear(): size = " << mm.size() << endl;
}

int main() {
    learnMultiMap();
    return 0;
}