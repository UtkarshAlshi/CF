#include <iostream>
using namespace std;

bool canMake(int x) {
    for (int q = 0; q <= 100; ++q) {
        if (x - 111 * q >= 0 && (x - 111 * q) % 11 == 0)
            return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        cout << (canMake(x) ? "YES" : "NO") << '\n';
    }
    return 0;
}
