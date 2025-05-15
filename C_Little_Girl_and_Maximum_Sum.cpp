#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int& num : a) cin >> num;
    
    vector<long long> freq(n + 1, 0);
    while (q--) {
        int l, r;
        cin >> l >> r;
        freq[l - 1] += 1;
        if (r < n) freq[r] -= 1;
    }
    
    for (int i = 1; i <= n; ++i)
        freq[i] += freq[i - 1];
    
    vector<long long> frequencies(freq.begin(), freq.begin() + n);
    sort(a.begin(), a.end());
    sort(frequencies.begin(), frequencies.end());
    
    long long sum = 0;
    for (int i = 0; i < n; ++i)
        sum += (long long)a[i] * frequencies[i];
    
    cout << sum << '\n';
    return 0;
}
