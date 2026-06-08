#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    set<string> s;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char num = board[i][j];

            if (num != '.') {
                string row = string(1, num) + "row" + to_string(i);
                string col = string(1, num) + "col" + to_string(j);
                string box = string(1, num) + "box" + to_string(i/3) + to_string(j/3);

                if (s.count(row) || s.count(col) || s.count(box))
                    return false;

                s.insert(row);
                s.insert(col);
                s.insert(box);
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    if (isValidSudoku(board))
        cout << "Valid Sudoku";
    else
        cout << "Invalid Sudoku";

    return 0;
}