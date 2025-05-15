#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> ABs, BAs;
    int n = s.size();
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == 'A' && s[i+1] == 'B') {
            ABs.push_back(i);
        } else if (s[i] == 'B' && s[i+1] == 'A') {
            BAs.push_back(i);
        }
    }
    
    if (ABs.empty() || BAs.empty()) {
        cout << "NO\n";
        return 0;
    }
    
    // Check AB followed by BA
    int a = ABs[0];
    int target = a + 2;
    auto it = lower_bound(BAs.begin(), BAs.end(), target);
    if (it != BAs.end()) {
        cout << "YES\n";
        return 0;
    }
    
    // Check BA followed by AB
    int b = BAs[0];
    target = b + 2;
    auto it2 = lower_bound(ABs.begin(), ABs.end(), target);
    if (it2 != ABs.end()) {
        cout << "YES\n";
        return 0;
    }
    
    cout << "NO\n";
    return 0;
}
