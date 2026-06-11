#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int>& nums, vector<vector<int>>& ans, int index) {
    if (index == nums.size()) {
        ans.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        solve(nums, ans, index + 1);
        swap(nums[index], nums[i]); // backtrack
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;

    solve(nums, ans, 0);

    for (auto p : ans) {
        for (int x : p) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}