#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isomorphicString(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> mapST, mapTS;

        for (int i = 0; i < s.length(); i++) {
            char sc = s[i];
            char tc = t[i];

            if (mapST.count(sc) && mapST[sc] != tc) return false;
            if (mapTS.count(tc) && mapTS[tc] != sc) return false;

            mapST[sc] = tc;
            mapTS[tc] = sc;
        }

        return true;
    }
};

int main() {
    Solution sol;
    string s = "egg", t = "add";
    cout << boolalpha << sol.isomorphicString(s, t) << endl;  // Output: true

    s = "foo", t = "bar";
    cout << boolalpha << sol.isomorphicString(s, t) << endl;  // Output: false

    s = "paper", t = "title";
    cout << boolalpha << sol.isomorphicString(s, t) << endl;  // Output: true

    return 0;
}