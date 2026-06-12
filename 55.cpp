#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};

    int maxReach = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (i > maxReach) {
            cout << "false";
            return 0;
        }

        maxReach = max(maxReach, i + nums[i]);
    }

    cout << "true";

    return 0;
}