#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {

            // Check if element already exists
            if(mp.find(nums[i]) != mp.end()) {

                // Check index difference
                if(i - mp[nums[i]] <= k) {
                    return true;
                }
            }

            // Store latest index
            mp[nums[i]] = i;
        }

        return false;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 3, 1};
    int k = 3;

    if(obj.containsNearbyDuplicate(nums, k)) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}