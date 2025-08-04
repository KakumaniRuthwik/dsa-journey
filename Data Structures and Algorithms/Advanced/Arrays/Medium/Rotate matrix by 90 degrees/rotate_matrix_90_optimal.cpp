#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotateMatrix(vector<vector<int>>& matrix) {
    int size = matrix.size();

    // Transpose the matrix
    for(int rowIndex = 0; rowIndex < size; rowIndex++) {
        for(int colIndex = 0; colIndex < rowIndex; colIndex++) {
            swap(matrix[rowIndex][colIndex], matrix[colIndex][rowIndex]);
        }
    }

    // Reverse each row
    for(int index = 0; index < size; index++) {
        reverse(matrix[index].begin(), matrix[index].end());
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotateMatrix(matrix);

    cout << "Rotated Matrix by 90 degrees clockwise:" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}