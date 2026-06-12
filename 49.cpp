#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    unordered_map<string, vector<string>> mp;

    for (string s : strs) {
        string temp = s;
        sort(temp.begin(), temp.end());
        mp[temp].push_back(s);
    }

    for (auto &it : mp) {
        cout << "[ ";
        for (string s : it.second) {
            cout << s << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}