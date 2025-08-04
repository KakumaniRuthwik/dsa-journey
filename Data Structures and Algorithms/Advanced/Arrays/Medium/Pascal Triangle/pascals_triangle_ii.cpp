#include <iostream>
#include <vector>
using namespace std;

vector<int> pascal_triangle_row(int r) {
    vector<int> result(r);
    result[0] = 1;

    for (int index = 1; index < r; index++) {
        result[index] = (result[index - 1] * (r - index)) / index;
    }

    return result;
}

int main() {
    int row = 5;
    vector<int> result = pascal_triangle_row(row);

    for (int value : result) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}