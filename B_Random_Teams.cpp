#include <iostream>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    // For minimum pairs: distribute as evenly as possible
    long long q = n / m;  // base number of participants per team
    long long r = n % m;  // remainder participants
    
    // r teams will have (q+1) participants, (m-r) teams will have q participants
    long long kmin = r * q * (q + 1) / 2 + (m - r) * q * (q - 1) / 2;
    
    // For maximum pairs: put minimum in (m-1) teams, rest in 1 team
    // (m-1) teams with 1 participant each, 1 team with (n-m+1) participants
    long long large_team_size = n - m + 1;
    long long kmax = large_team_size * (large_team_size - 1) / 2;
    
    cout << kmin << " " << kmax << endl;
    
    return 0;
}