#include<iostream>
#include<map>
using namespace std;

void learnMap() {
    map<string, int> mp;

    // Inserting elements
    mp["apple"] = 5;
    mp["banana"] = 2;
    mp["cherry"] = 7;

    // Another way to insert
    mp.insert({"date", 4});
    mp.insert(make_pair("elderberry", 3));

    cout << "Map content (sorted by key):\n";
    for (auto p : mp) {
        cout << p.first << " : " << p.second << endl;
    }

    // Accessing values
    cout << "mp[\"banana\"]: " << mp["banana"] << endl;

    // Check if key exists using .count()
    if (mp.count("fig")) {
        cout << "fig exists\n";
    } else {
        cout << "fig not found\n";
    }

    // Erasing a key
    mp.erase("banana");
    cout << "After erase(\"banana\"):\n";
    for (auto p : mp) {
        cout << p.first << " : " << p.second << endl;
    }

    // Lower and upper bound
    auto lb = mp.lower_bound("cherry");  // ≥ cherry
    auto ub = mp.upper_bound("cherry");  // > cherry

    if (lb != mp.end()) cout << "Lower bound of cherry: " << lb->first << endl;
    if (ub != mp.end()) cout << "Upper bound of cherry: " << ub->first << endl;

    // Clear map
    mp.clear();
    cout << "After clear(), size = " << mp.size() << endl;
}

int main() {
    learnMap();
    return 0;
}