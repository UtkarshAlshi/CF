#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[200005];
    int t, n, ji, ou;
    long long sum;

    cin >> t;
    while (t--) {
        ji = 0;
        ou = 0;
        sum = 0;

        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0)
                ou++;
            else
                ji++;
            sum += a[i];
        }

        sort(a + 1, a + n + 1);

        if (ji == 0 || ji == n) {
            // All are even or all are odd
            cout << a[n] << endl;
        } else {
            cout << sum - ji + 1 << endl;
        }
    }

    return 0;
}
