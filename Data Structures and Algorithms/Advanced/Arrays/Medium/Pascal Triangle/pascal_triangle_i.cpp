#include <iostream>
using namespace std;

// Function to compute nCr efficiently
int nCr(int n, int r) {
    if (r > n - r) {
        r = n - r;
    }

    int result = 1;
    for (int i = 0; i < r; i++) {
        result = result * (n - i);
        result = result / (i + 1);
    }

    return result;
}

// Function to get Pascal Triangle value at (r, c) (1-based)
int pascal_triangle_i(int r, int c) {
    return nCr(r - 1, c - 1);
}

int main() {
    // Sample input
    int r = 5, c = 3;
    cout << "Value at (" << r << ", " << c << ") in Pascal's Triangle: " 
         << pascal_triangle_i(r, c) << endl;

    return 0;
}