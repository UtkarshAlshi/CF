#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define F first
#define S second
#define mp make_pair
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define loop(i, a, b) for (int i = a; i < b; i++)
#define rloop(i, a, b) for (int i = a; i >= b; i--)
#define print(x) cout << x << endl;
#define setbits(x) __builtin_popcount(x)
#define zrobits(x) __builtin_ctz(x)
#define sp(x, y) fixed << setprecision(y) << x
#define mod 1000000007
#define inf 1e18
#define PI 3.14159265358979323846
#define M 998244353
#define MAX 1000000
#define EPS 1e-9
#define ll long long
#define ull unsigned long long
#define ld long double
#define sz(x) (int)x.size()
#define mem(a, b) memset(a, b, sizeof(a))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / __gcd(a, b)

const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    loop(i, 0, n) cin >> a[i];
    vi b;
    set<int> s;
    for (auto x : a) {
        if (!s.count(x)) {
            b.pb(x);
            s.insert(x);
        }
    }
    if (sz(b) > k) {
        print(-1)
        return;
    }
    int x = 1;
    while (sz(b) < k) {
        b.pb(x);
        x++;
        if (x > n) x = 1;
    }
    vi ans;
    while (sz(ans) < 10000) for (auto y : b) ans.pb(y);
    ans.resize(10000);
    int i = 0, j = 0;
    while (i < sz(a) && j < sz(ans)) {
        if (a[i] == ans[j]) i++;
        j++;
    }
    if (i == sz(a)) {
        print(j)
        loop(p, 0, j) cout << ans[p] << " ";
        cout << endl;
    } else print(-1)
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
