#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> v;

    for (int x : nums1)
        v.push_back(x);

    for (int x : nums2)
        v.push_back(x);

    sort(v.begin(), v.end());

    int n = v.size();

    if (n % 2 == 1)
        return v[n / 2];

    return (v[n / 2] + v[n / 2 - 1]) / 2.0;
}

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    cout << findMedianSortedArrays(nums1, nums2);

    return 0;
}