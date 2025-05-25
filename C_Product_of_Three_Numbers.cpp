#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long n;
        cin >> n;
        
        bool found = false;
        long long a, b, c;
        
        // Try different values for a and b
        for (a = 2; a * a * a <= n && !found; a++) {
            for (b = a + 1; a * b * b <= n && !found; b++) {
                if (n % (a * b) == 0) {
                    c = n / (a * b);
                    // Check if c is valid (>= 2 and different from a and b)
                    if (c >= 2 && c != a && c != b) {
                        found = true;
                    }
                }
            }
        }
        
        if (found) {
            cout << "YES\n";
            cout << a << " " << b << " " << c << "\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}