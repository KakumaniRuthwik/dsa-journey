#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        // Return empty string if array is empty
        if (str.empty()) {
            return "";
        }

        // Sort the array
        sort(str.begin(), str.end());

        // Get the first and last elements after sorting
        string firstElement = str.front();
        string lastElement = str.back();

        // Find the minimum length among both
        int minimumLength = min(firstElement.length(), lastElement.length());

        // Build the common prefix
        string resultantString = "";
        for (int i = 0; i < minimumLength; i++) {
            if (firstElement[i] != lastElement[i]) {
                return resultantString;
            }
            resultantString += firstElement[i];
        }

        return resultantString;
    }
};

int main() {
    Solution solution;

    // Test Case 1
    vector<string> str1 = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << solution.longestCommonPrefix(str1) << endl;

    // Test Case 2
    vector<string> str2 = {"dog", "racecar", "car"};
    cout << "Longest Common Prefix: " << solution.longestCommonPrefix(str2) << endl;

    // Test Case 3
    vector<string> str3 = {"interview", "internet", "internal", "into"};
    cout << "Longest Common Prefix: " << solution.longestCommonPrefix(str3) << endl;

    // Test Case 4 (Empty)
    vector<string> str4 = {};
    cout << "Longest Common Prefix: " << solution.longestCommonPrefix(str4) << endl;

    return 0;
}