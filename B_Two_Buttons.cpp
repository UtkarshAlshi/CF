#include <iostream>
 
int minClicks(int n, int m) {
    // If n >= m, we just need to subtract (n-m) times
    if (n >= m) {
        return n - m;
    }
    
    // Work backwards from m to n
    int clicks = 0;
    while (m > n) {
        // If m is odd, we need to add 1 (reverse of subtract 1)
        if (m % 2 != 0) {
            m++;
            clicks++;
        }
        // Divide by 2 (reverse of multiply by 2)
        m /= 2;
        clicks++;
    }
    
    // After getting to a value <= n, we may need additional subtractions
    return clicks + (n - m);
}
 
int main() {
    int n, m;
    std::cin >> n >> m;
    
    std::cout << minClicks(n, m) << std::endl;
    
    return 0;
}