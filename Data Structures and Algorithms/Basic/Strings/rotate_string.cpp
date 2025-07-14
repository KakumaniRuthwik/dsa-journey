#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string& s, string& goal) {
        // If lengths are not equal, they can never be rotations of each other
        if (s.length() != goal.length()) {
            return false;
        }

        // Concatenate string with itself
        string concat = s + s;

        // If goal is a substring of concatenated string, it's a rotation
        return concat.find(goal) != string::npos;
    }
};

// Main function to test the solution
int main() {
    Solution solution;
    string s = "abcde";
    string goal = "cdeab";

    if (solution.rotateString(s, goal)) {
        cout << "Yes, '" << goal << "' is a rotation of '" << s << "'." << endl;
    } else {
        cout << "No, '" << goal << "' is NOT a rotation of '" << s << "'." << endl;
    }

    return 0;
}