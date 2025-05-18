#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> exams(n);  // {ai, bi}

    for (int i = 0; i < n; ++i) {
        cin >> exams[i].first >> exams[i].second;
    }

    sort(exams.begin(), exams.end());  // Sort by ai (record date)

    int last_day = 0;

    for (int i = 0; i < n; ++i) {
        int ai = exams[i].first;
        int bi = exams[i].second;

        if (bi >= last_day) {
            last_day = bi;
        } else {
            last_day = ai;
        }
    }

    cout << last_day << endl;

    return 0;
}
