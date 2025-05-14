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
#define sp(x, y) fixed << setprecision(y) << x
#define mem(a, b) memset(a, b, sizeof(a))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / __gcd(a, b)

const int MOD = 1e9 + 7;
const int INF = 1e18;

pair<string, string> f(int m, int s) {
    if ((s == 0 && m > 1) || s > 9 * m) return {"-1", "-1"};
    if (s == 0) return {"0", "0"};

    string mn(m, '0'), mx(m, '0');
    int r = s;

    int fd = 1, lim = 9 * (m - 1);
    if (r > lim + 1) fd += (r - lim - 1);
    mn[0] = '0' + fd;
    r -= fd;

    rloop(i, m - 1, 1) {
        int d = min(9ll, r);
        mn[i] = '0' + d;
        r -= d;
    }

    r = s;
    loop(i, 0, m) {
        int d = min(9ll, r);
        mx[i] = '0' + d;
        r -= d;
    }

    return {mn, mx};
}

void solve() {
    int m, s;
    cin >> m >> s;
    auto ans = f(m, s);
    cout << ans.F << " " << ans.S << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
