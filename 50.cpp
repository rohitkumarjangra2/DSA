#include <iostream>
using namespace std;

int main() {
    double x = 2.0;
    int n = 10;

    long long N = n;

    if (N < 0) {
        x = 1 / x;
        N = -N;
    }

    double result = 1;

    while (N > 0) {
        if (N % 2 == 1) {
            result *= x;
        }

        x *= x;
        N /= 2;
    }

    cout << result << endl;

    return 0;
}