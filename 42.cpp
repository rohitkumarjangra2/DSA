#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    int n = height.size();

    int left = 0;
    int right = n - 1;

    int leftMax = 0;
    int rightMax = 0;

    int water = 0;

    while (left < right) {

        if (height[left] < height[right]) {

            if (height[left] >= leftMax) {
                leftMax = height[left];
            }
            else {
                water += leftMax - height[left];
            }

            left++;
        }
        else {

            if (height[right] >= rightMax) {
                rightMax = height[right];
            }
            else {
                water += rightMax - height[right];
            }

            right--;
        }
    }

    cout << "Trapped Water = " << water;

    return 0;
