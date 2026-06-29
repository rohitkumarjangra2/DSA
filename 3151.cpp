#include <iostream>
#include <vector>
using namespace std;

bool isArraySpecial(vector<int>& nums) {

    for (int i = 1; i < nums.size(); i++) {

        if ((nums[i] % 2) == (nums[i - 1] % 2))
            return false;
    }

    return true;
}

int main() {

    vector<int> nums = {1, 2, 3, 4};

    if (isArraySpecial(nums))
        cout << "true";
    else
        cout << "false";

    return 0;
}