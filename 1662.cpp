#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    string s1 = "";
    string s2 = "";

    for (int i = 0; i < word1.size(); i++) {
        s1 += word1[i];
    }

    for (int i = 0; i < word2.size(); i++) {
        s2 += word2[i];
    }

    return s1 == s2;
}

int main() {
    vector<string> word1 = {"ab", "ca"};
    vector<string> word2 = {"a", "bc"};

    if (arrayStringsAreEqual(word1, word2))
        cout << "true";
    else
        cout << "false";

    return 0;
}
