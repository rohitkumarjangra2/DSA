#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
}

int main() {
    vector<int> nums = {1,3,5,6};
    int target = 5;

    cout << searchInsert(nums, target);

    return 0;
}