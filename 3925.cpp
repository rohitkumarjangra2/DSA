#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> concatenateAndReverse(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        // Add original array
        for (int i = 0; i < n; i++) {
            ans.push_back(nums[i]);
        }

        // Add reverse array
        for (int i = n - 1; i >= 0; i--) {
            ans.push_back(nums[i]);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 3};

    vector<int> result = obj.concatenateAndReverse(nums);

    cout << "Output: ";

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}