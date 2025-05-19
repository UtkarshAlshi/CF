#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n, -1));
        int num = 0;
        int x = n/2, y = n/2;
        if (n % 2 == 0) { x--; y--; } // Adjust for even n
        
        int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}}; // R, D, L, U
        int dir = 0, steps = 1;
        
        grid[x][y] = num++;
        while (num < n*n) {
            for (int d = 0; d < 2; ++d) { // Two directions per step
                for (int s = 0; s < steps; ++s) {
                    x += dirs[dir][0];
                    y += dirs[dir][1];
                    if (x < 0 || x >= n || y < 0 || y >= n) continue;
                    if (grid[x][y] == -1) {
                        grid[x][y] = num++;
                    }
                }
                dir = (dir + 1) % 4;
            }
            steps++;
        }
        
        for (auto &row : grid) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
