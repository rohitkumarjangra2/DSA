#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIndex = 0;
        int maxIndex = 0;

        // Find indices of minimum and maximum elements
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }

            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }

        // Make sure minIndex < maxIndex
        int left = min(minIndex, maxIndex);
        int right = max(minIndex, maxIndex);

        // Case 1: Remove both from front
        int front = right + 1;

        // Case 2: Remove both from back
        int back = n - left;

        // Case 3: One from front and one from back
        int mixed = (left + 1) + (n - right);

        return min(front, min(back, mixed));
    }
};
int main() {
    Solution obj;

    vector<int> nums = {2, 10, 7, 5, 4, 1, 8, 6};

    cout << "Minimum deletions: "
         << obj.minimumDeletions(nums);

    return 0;
}