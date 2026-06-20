#include <iostream>
#include <string>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size())
        return false;

    int freq[26] = {0};

    for (int i = 0; i < s.size(); i++) {
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0)
            return false;
    }

    return true;
}

int main() {
    string s, t;

    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter second string: ";
    cin >> t;

    if (isAnagram(s, t))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
