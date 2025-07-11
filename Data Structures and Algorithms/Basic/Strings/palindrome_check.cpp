#include<iostream>
using namespace std;

// Function to check if a given string is a palindrome
bool palindromeCheck(string& s) {
    if (s.empty()) return true;  // An empty string is considered a palindrome

    int start = 0;
    int end = s.size() - 1;

    // Loop until the two pointers meet
    while (start < end) {
        if (s[start] != s[end]) {
            return false; // If mismatch, not a palindrome
        }
        start++;
        end--;
    }
    return true; // All characters matched
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    bool isPalindrome = palindromeCheck(input);

    if (isPalindrome) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is NOT a palindrome." << endl;
    }

    return 0;
}