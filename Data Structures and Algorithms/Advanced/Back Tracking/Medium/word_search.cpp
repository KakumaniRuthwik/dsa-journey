#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool wordExist(vector<vector<char>>& board, string& word, int index, int i, int j) {
    // Base case: full word matched
    if (index == word.length()) return true;

    // Boundary + mismatch check
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()
        || board[i][j] != word[index]) {
        return false;
    }

    // Mark current cell as visited
    char letter = board[i][j];
    board[i][j] = '#';

    // Explore all 4 directions
    bool found =
        wordExist(board, word, index + 1, i - 1, j) ||  // up
        wordExist(board, word, index + 1, i + 1, j) ||  // down
        wordExist(board, word, index + 1, i, j - 1) ||  // left
        wordExist(board, word, index + 1, i, j + 1);    // right

    // Backtrack
    board[i][j] = letter;

    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    int n = board.size();
    int m = board[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == word[0]) {
                if (wordExist(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "ABCCED";

    if (exist(board, word))
        cout << "Word exists in the board\n";
    else
        cout << "Word does NOT exist in the board\n";

    return 0;
}
