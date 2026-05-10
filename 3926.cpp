#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    bool isLower(char c) {
        return c >= 'a' && c <= 'z';
    }

    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {

        // Join all chunks
        string s = "";

        for (string part : chunks) {
            s += part;
        }

        unordered_map<string, int> freq;

        string word = "";

        int n = s.size();

        for (int i = 0; i < n; i++) {

            char c = s[i];

            // lowercase letter
            if (isLower(c)) {
                word += c;
            }

            // valid hyphen
            else if (
                c == '-' &&
                i > 0 &&
                i < n - 1 &&
                isLower(s[i - 1]) &&
                isLower(s[i + 1])
            ) {
                word += c;
            }

            // separator
            else {
                if (!word.empty()) {
                    freq[word]++;
                    word = "";
                }
            }
        }

        // Last word
        if (!word.empty()) {
            freq[word]++;
        }

        vector<int> ans;

        for (string q : queries) {
            ans.push_back(freq[q]);
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<string> chunks = {"hello wor", "ld hello"};
    vector<string> queries = {"hello", "world", "wor"};

    vector<int> result =
        obj.countWordOccurrences(chunks, queries);

    cout << "Output: ";

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
