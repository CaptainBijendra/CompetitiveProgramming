#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

#define MAX_N 1005
#define f first
#define s second

using namespace std;

bool block[MAX_N][MAX_N];

int DP[MAX_N][MAX_N];
int N, T;

int main() {
    cin >> N >> T;

    int x, y;
    for (int i = 0; i < T; i ++) {
        cin >> x >> y;
        block[x - 1][y - 1] = true;
    }
    
    int ans = 0;
    
    for (int i = N - 1; i >= 0; i --)
        for (int j = N - 1; j >= 0; j --) {
            if (block[i][j])
                continue;
            
            DP[i][j] = min(min(DP[i + 1][j], DP[i][j + 1]), DP[i + 1][j + 1]) + 1;
            ans = max(ans, DP[i][j]);
        }

    cout << ans << endl;
    return (0);
}