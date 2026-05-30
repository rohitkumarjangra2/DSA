#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> mp;
    int left = 0, ans = 0;

    for (int right = 0; right < s.size(); right++) {
        if (mp.count(s[right])) {
            left = max(left, mp[s[right]] + 1);
        }

        mp[s[right]] = right;
        ans = max(ans, right - left + 1);
    }

    return ans;
}

int main() {
    string s = "abcabcbb";

    cout << lengthOfLongestSubstring(s);

    return 0;
}