#include<iostream>
#include<vector>
#include<string>
using namespace std;

void generate(vector<string>& result, string s, int n, int open, int close) {

    // If the string is complete
    if (open == n && close == n) {
        result.push_back(s);
        return;
    }

    // If we can still add '('
    if (open < n) {
        generate(result, s + "(", n, open + 1, close);
    }

    // If we can add ')' (only if close < open)
    if (close < open) {
        generate(result, s + ")", n, open, close + 1);
    }
}

int main() {
    int n;
    cin >> n;

    vector<string> result;

    generate(result, "", n, 0, 0);

    for (string &s : result) {
        cout << s << endl;
    }

    return 0;
}
