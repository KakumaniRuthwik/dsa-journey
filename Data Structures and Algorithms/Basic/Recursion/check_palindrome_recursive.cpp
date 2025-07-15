#include <bits/stdc++.h>
using namespace std;

string reverseStr(const string& s, string modify, int index) {
    if (index < 0) {
        return modify;
    }
    modify += s[index];
    return reverseStr(s, modify, index - 1);
}

bool palindromeCheck(string& s) {
    string modify = reverseStr(s, "", s.length() - 1);
    return (modify == s);
}

int main() {
    string s = "madam";
    
    if (palindromeCheck(s)) {
        cout << "Yes, it's a palindrome!" << endl;
    } else {
        cout << "No, it's not a palindrome." << endl;
    }

    return 0;
}