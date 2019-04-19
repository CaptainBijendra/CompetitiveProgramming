/*
#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define INF 2000000009
#define MAX_N 30005
#define MAX_V 255
#define f first
#define s second

using namespace std;

long long DP[MAX_N][MAX_V * 3], cnt[MAX_N];
int N, D;

int main() {
    cin >> N >> D;
    
    int x;
    
    for (int i = 0; i < N; i ++) {
        cin >> x;
        cnt[x] ++;        
    }
    
    for (int i = 0; i < MAX_N; i ++)
        for (int j = 0; j < 3 * MAX_V; j ++)
            DP[i][j] = -1;
    
    DP[D][MAX_V] = cnt[D];

    long long ans = cnt[D];

    for (int i = D; i < MAX_N; i ++) {
        for (int j = 0; j <= 2 * MAX_V; j ++) {
            if (DP[i][j] < 0)
                continue;
                
            //j - 1
            //prev_dist = D + j - MAXV
			if (i + D + (j - MAX_V) + 1 > i && i + D + (j - MAX_V) + 1 < MAX_N)
			    DP[i + D + (j - MAX_V) + 1][j + 1] = max(DP[i + D + (j - MAX_V) + 1][j + 1], DP[i][j] + cnt[i + D + (j - MAX_V) + 1]);
			if (i + D + (j - MAX_V) > i && i + D + (j - MAX_V) < MAX_N)
                DP[i + D + (j - MAX_V)][j] = max(DP[i + D + (j - MAX_V)][j], DP[i][j] + cnt[i + D + (j - MAX_V)]);
			if (j > 0 && i + D + (j - MAX_V) - 1 > i && i + D + (j - MAX_V) - 1 < MAX_N)
				DP[i + D + (j - MAX_V) - 1][j - 1] = max(DP[i + D + (j - MAX_V) - 1][j - 1], DP[i][j] + cnt[i + D + (j - MAX_V) - 1]);
		    
		    ans = max(ans, DP[i][j]);
        }
    }
    
    cout << ans << endl;
    return (0);
}