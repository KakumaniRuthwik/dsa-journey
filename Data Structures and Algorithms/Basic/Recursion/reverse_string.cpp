#include <iostream>
#include <vector>
using namespace std;

void reverseHelper(vector<char>& s, vector<char>& reversed, int index) {
    if(index < 0) {
        return;
    }

    reversed.push_back(s[index]);
    reverseHelper(s, reversed, index - 1);
}

vector<char> reverseString(vector<char>& s) {
    vector<char> reversed;
    reverseHelper(s, reversed, s.size() - 1);
    return reversed;
}

int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    vector<char> result = reverseString(s);
    for(char c : result) {
        cout << c << " ";
    }
    return 0;
}