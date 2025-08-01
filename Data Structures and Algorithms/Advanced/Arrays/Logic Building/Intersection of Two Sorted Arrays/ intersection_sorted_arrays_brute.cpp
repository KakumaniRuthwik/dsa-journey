#include <iostream>
#include <vector>
using namespace std;

vector<int> intersection_brute(vector<int>& a, vector<int>& b) {
    vector<int> result;
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            if (a[i] == b[j]) {
                result.push_back(a[i]);
                break;
            }
        }
    }
    return result;
}

int main() {
    vector<int> a = {1, 2, 2, 3, 4};
    vector<int> b = {2, 2, 4, 6};

    vector<int> result = intersection_brute(a, b);

    cout << "Brute Force Intersection: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}