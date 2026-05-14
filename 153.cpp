#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};

    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }

    cout << "Minimum element = " << nums[left];

    return 0;
}