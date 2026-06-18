#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        for (int i = 0; i < n; i++) {
            pq.push({matrix[i][0], i, 0});
        }

        while (k > 1) {
            auto curr = pq.top();
            pq.pop();

            int row = curr[1];
            int col = curr[2];

            if (col + 1 < n) {
                pq.push({matrix[row][col + 1], row, col + 1});
            }

            k--;
        }

        return pq.top()[0];
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };

    int k = 8;

    Solution obj;
    cout << "Kth Smallest Element = "
         << obj.kthSmallest(matrix, k);

    return 0;
}