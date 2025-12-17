#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(vector<string>& board, int row, int col) {
    int n = board.size();
    int r = row, c = col;

    // check column above
    while (r >= 0) {
        if (board[r][c] == 'Q') return false;
        r--;
    }

    // check top-left diagonal
    r = row; c = col;
    while (r >= 0 && c >= 0) {
        if (board[r][c] == 'Q') return false;
        r--; c--;
    }

    // check top-right diagonal
    r = row; c = col;
    while (r >= 0 && c < n) {
        if (board[r][c] == 'Q') return false;
        r--; c++;
    }

    return true;
}

void solve(vector<string>& board, int row, vector<vector<string>>& result) {
    if (row == board.size()) {
        result.push_back(board);
        return;
    }

    for (int col = 0; col < board.size(); col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 'Q';
            solve(board, row + 1, result);
            board[row][col] = '.';
        }
    }
}

int main() {
    int n = 4;   // change n as needed

    vector<string> board(n, string(n, '.'));
    vector<vector<string>> result;

    solve(board, 0, result);

    // print all solutions
    for (auto& sol : result) {
        for (auto& row : sol) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
