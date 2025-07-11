#include <iostream>
#include <string>
using namespace std;

class Solution {	
public:		
    string largeOddNum(string& s) {
        int leadingZero = 0;
        int rightOdd = -1;

        int size = s.length();

        // Find rightmost odd digit
        for (int i = size - 1; i >= 0; i--) {
            if ((s[i] - '0') % 2 == 1) {
                rightOdd = i;
                break;
            }
        }

        // If no odd digit found, return empty string
        if (rightOdd == -1) return "";

        // Skip all leading zeros
        while (leadingZero <= rightOdd && s[leadingZero] == '0') {
            leadingZero++;
        }

        // Return substring from leadingZero to rightOdd (inclusive)
        return s.substr(leadingZero, rightOdd - leadingZero + 1);
    }
};

int main() {
    Solution sol;
    string input;
    cout << "Enter a string of digits: ";
    cin >> input;

    string result = sol.largeOddNum(input);
    cout << "Largest odd number substring: " << result << endl;

    return 0;
}