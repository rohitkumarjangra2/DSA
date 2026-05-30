#include <iostream>
#include <climits>
using namespace std;

int reverseInteger(int x) {
    long long rev = 0;

    while (x != 0) {
        rev = rev * 10 + x % 10;
        x /= 10;

        if (rev > INT_MAX || rev < INT_MIN)
            return 0;
    }

    return rev;
}

int main() {
    int x = 123;

    cout << reverseInteger(x);

    return 0;
}