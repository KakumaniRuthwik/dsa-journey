#include <iostream>
#include <vector>
using namespace std;

void rotate_matrix_90_brute(vector<vector<int>>& matrix) {
    int size = matrix.size();
    vector<vector<int>> result(size, vector<int>(size, 0));

    for (int rowIndex = size - 1; rowIndex >= 0; rowIndex--) {
        for (int colIndex = 0; colIndex < size; colIndex++) {
            result[colIndex][size - rowIndex - 1] = matrix[rowIndex][colIndex];
        }
    }

    for (int rowIndex = 0; rowIndex < size; rowIndex++) {
        for (int colIndex = 0; colIndex < size; colIndex++) {
            matrix[rowIndex][colIndex] = result[rowIndex][colIndex];
        }
    }
}

void print_matrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int v : row) {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12},
        {13,14, 15,16}
    };

    cout << "Original matrix:\n";
    print_matrix(matrix);

    rotate_matrix_90_brute(matrix);

    cout << "\nRotated matrix (90 degrees clockwise) - brute force:\n";
    print_matrix(matrix);

    return 0;
}