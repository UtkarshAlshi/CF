#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) c[i] = a[i] - b[i];
    sort(c.begin(), c.end());
    long long total = 0;
    for (int i = 0; i < n; ++i) {
        int target = -c[i];
        auto it = upper_bound(c.begin() + i + 1, c.end(), target);
        total += c.end() - it;
    }
    cout << total << '\n';
    return 0;
}
