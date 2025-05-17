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
    int n;
    cin >> n;
    if (n == 0) {
        print(0)
        return;
    }
    vector<pair<int, int>> a(n);
    loop(i, 0, n) cin >> a[i].F >> a[i].S;
    if (n == 1) {
        print(1)
        return;
    }
    int ans = 1, p = a[0].F;
    loop(i, 1, n - 1) {
        int x = a[i].F, h = a[i].S;
        if (x - h > p) {
            ans++;
            p = x;
        } else if (x + h < a[i + 1].F) {
            ans++;
            p = x + h;
        } else p = x;
    }
    ans++;
    print(ans)
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
