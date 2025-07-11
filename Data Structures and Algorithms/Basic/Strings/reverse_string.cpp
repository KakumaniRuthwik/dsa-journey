#include <iostream>
#include <vector>
using namespace std;

void reverseString(vector<char>& s) {
    if (s.empty()) return;

    int start = 0, end = s.size() - 1;
    while (start < end) {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}

int main() {
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;

    vector<char> s(n);
    cout << "Enter the characters:\n";
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    reverseString(s);

    cout << "Reversed string: ";
    for (char c : s) {
        cout << c;
    }
    cout << endl;

    return 0;
}