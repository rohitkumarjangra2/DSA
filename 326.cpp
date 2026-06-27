#include <iostream>
using namespace std;

bool isPowerOfThree(int n) {
    if (n == 1)
        return true;

    if (n <= 0 || n % 3 != 0)
        return false;

    return isPowerOfThree(n / 3);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isPowerOfThree(n))
        cout << "True";
    else
        cout << "False";

    return 0;
}