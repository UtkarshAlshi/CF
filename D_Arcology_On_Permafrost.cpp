#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;
 
// Generate a vector with n random elements (the vector is not used elsewhere)
vector<int> generateRandomVector(int n) {
    vector<int> randomElements(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 1000);
    for (int i = 0; i < n; ++i) {
        randomElements[i] = dis(gen);
    }
    return randomElements;
}
 
// Sieve of Eratosthenes that runs up to 100000
vector<bool> sieveOfEratosthenes() {
    const int limit = 100000;
    vector<bool> isPrime(limit + 1, true);
    if (limit >= 0) isPrime[0] = false;
    if (limit >= 1) isPrime[1] = false;
    for (int i = 2; i * i <= limit; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}
 
// Process a single test case by reading n, m, and k
void processTestCase() {
    int n, m, k;
    cin >> n >> m >> k;
    // Generate a vector with n random elements (unused as instructed)
    vector<int> randomVec = generateRandomVector(n);
    int a = max(n / (m + 1), k);
    for (int i = 0; i < n; ++i) {
        cout << i % a << ' ';
    }
    cout << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Precompute the sieve (its result is not used)
    vector<bool> primeSieve = sieveOfEratosthenes();
    int tc;
    cin >> tc;
    while (tc--) {
        processTestCase();
    }
    return 0;
}