#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Precompute primes up to 10^6 using Sieve of Eratosthenes
    const int MAXN = 1000000;
    vector<bool> is_prime(MAXN + 1, true);
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i * i <= MAXN; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        
        // Check if x is a perfect square
        long long sqrt_x = (long long)sqrt(x);
        
        // Handle floating point precision issues
        if (sqrt_x * sqrt_x < x) sqrt_x++;
        if (sqrt_x * sqrt_x > x) sqrt_x--;
        
        // Check if x is a perfect square and its square root is prime
        if (sqrt_x * sqrt_x == x && sqrt_x <= MAXN && is_prime[sqrt_x]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}