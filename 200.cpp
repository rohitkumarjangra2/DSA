#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int islands = 0;

        // Down, Up, Right, Left
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '1') {

                    islands++;

                    queue<pair<int, int>> q;
                    q.push({i, j});

                    // Mark as visited
                    grid[i][j] = '0';

                    while (!q.empty()) {

                        pair<int, int> curr = q.front();
                        q.pop();

                        int row = curr.first;
                        int col = curr.second;

                        // Check 4 directions
                        for (int k = 0; k < 4; k++) {

                            int newRow = row + dr[k];
                            int newCol = col + dc[k];

                            if (newRow >= 0 && newRow < m &&
                                newCol >= 0 && newCol < n &&
                                grid[newRow][newCol] == '1') {

                                q.push({newRow, newCol});
                                grid[newRow][newCol] = '0';
                            }
                        }
                    }
                }
            }
        }

        return islands;
    }
};

int main() {

    vector<vector<char>> grid = {
        {'1','1','0'},
        {'1','0','0'},
        {'0','1','1'}
    };

    Solution obj;

    cout << "Number of Islands = " << obj.numIslands(grid);

    return 0;
}