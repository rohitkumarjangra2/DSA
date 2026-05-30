#include <iostream>
#include <vector>
using namespace std;

string convert(string s, int numRows) {
    if (numRows == 1 || numRows >= s.size())
        return s;

    vector<string> rows(numRows);

    int currRow = 0;
    bool down = true;

    for (char c : s) {
        rows[currRow] += c;

        if (currRow == 0)
            down = true;
        else if (currRow == numRows - 1)
            down = false;

        currRow += down ? 1 : -1;
    }

    string ans;

    for (string row : rows)
        ans += row;

    return ans;
}

int main() {
    string s = "PAYPALISHIRING";
    int numRows = 3;

    cout << convert(s, numRows);

    return 0;
}