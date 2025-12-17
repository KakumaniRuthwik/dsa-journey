#include <iostream>
#include <vector>
#include <string>
using namespace std;

void dfs(vector<vector<int>>& maze, int n,
         int row, int col,
         string path, vector<string>& result) {

    if (row == n - 1 && col == n - 1) {
        result.push_back(path);
        return;
    }

    maze[row][col] = 0; // mark visited

    // Down
    if (row + 1 < n && maze[row + 1][col] == 1)
        dfs(maze, n, row + 1, col, path + 'D', result);

    // Left
    if (col - 1 >= 0 && maze[row][col - 1] == 1)
        dfs(maze, n, row, col - 1, path + 'L', result);

    // Right
    if (col + 1 < n && maze[row][col + 1] == 1)
        dfs(maze, n, row, col + 1, path + 'R', result);

    // Up
    if (row - 1 >= 0 && maze[row - 1][col] == 1)
        dfs(maze, n, row - 1, col, path + 'U', result);

    maze[row][col] = 1; // backtrack
}

vector<string> findPath(vector<vector<int>>& maze) {
    int n = maze.size();
    vector<string> result;

    if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
        return result;

    dfs(maze, n, 0, 0, "", result);
    return result;
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> paths = findPath(maze);

    for (auto& p : paths)
        cout << p << endl;

    return 0;
}
