#include <iostream>
#include <vector>
using namespace std;

vector<vector<string>> result;

bool isSafe(vector<string>& board, int row, int col, int n) {
    int r, c;

    for (r = 0; r < row; r++) {
        if (board[r][col] == 'Q')
            return false;
    }

    r = row;
    c = col;
    while (r >= 0 && c >= 0) {
        if (board[r][c] == 'Q')
            return false;
        r--;
        c--;
    }

    r = row;
    c = col;
    while (r >= 0 && c < n) {
        if (board[r][c] == 'Q')
            return false;
        r--;
        c++;
    }

    return true;
}

void solve(vector<string>& board, int row, int n) {
    if (row == n) {
        result.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solve(board, row + 1, n);
            board[row][col] = '.';
        }
    }
}

int main() {
    int n = 4;

    vector<string> board(n, string(n, '.'));

    solve(board, 0, n);

    for (auto solution : result) {
        for (auto row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}