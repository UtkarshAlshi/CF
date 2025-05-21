#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is_possible(ll n, ll m, ll k, ll x) {
    ll benches = m / (x + 1);
    ll remainder = m % (x + 1);
    ll max_per_row = benches * x + min(remainder, x);
    return n * max_per_row >= k;
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    ll left = 1, right = m;
    ll ans = m;

    while (left <= right) {
        ll mid = (left + right) / 2;
        if (is_possible(n, m, k, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
