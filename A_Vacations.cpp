#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e9

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<vector<int>> dp(n + 1, vector<int>(3, INF));
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        dp[i][0] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + 1;

        if (a[i - 1] == 1 || a[i - 1] == 3)
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);

        if (a[i - 1] == 2 || a[i - 1] == 3)
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
    }

    cout << min({dp[n][0], dp[n][1], dp[n][2]}) << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
    return 0;
}
