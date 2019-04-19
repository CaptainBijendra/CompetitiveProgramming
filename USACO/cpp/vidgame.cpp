#include <iostream>
#include <algorithm>

#define INF 200000009
#define MAX_N 55
#define MAX_V 100005

using namespace std;

int knap[MAX_N][1005], DP[MAX_N][MAX_V];

int cst[MAX_N], len[MAX_N], games[MAX_N][15][2];
int N, V;

int main() {
    cin >> N >> V;

    for (int i = 0; i < N; i ++) {
        cin >> cst[i] >> len[i];
        
        for (int j = 0; j < len[i]; j ++)
            cin >> games[i][j][0] >> games[i][j][1];
    }
    
    for (int i = 0; i < N; i ++) {
        for (int j = 1; j < 1005; j ++) 
            knap[i][j] = -INF;
    
        for (int j = 1; j <= V; j ++)
            DP[i][j] = -INF;
    }
    
    for (int i = 0; i < N; i ++) {
        for (int k = 0; k < len[i]; k ++) { 
            for (int j = 1005; j >= 0; j --) {
                if (j + games[i][k][0] >= 1005)
                    continue;
                
                if (knap[i][j] >= 0)
                    knap[i][j + games[i][k][0]] = max(knap[i][j + games[i][k][0]], knap[i][j] + games[i][k][1]);
            }
        }
    }
    
    int ans = 0;
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j <= V; j ++) {
            if (j + cst[i] > V)
                break;
            
            for (int k = 0; k < 1005; k ++) {
                if (DP[i][j] >= 0 && knap[i][k]) { 
                    if (j + cst[i] + k <= V) {
                        DP[i + 1][j + cst[i] + k] = max(DP[i + 1][j + cst[i] + k], DP[i][j] + knap[i][k]);
                        ans = max(ans, DP[i + 1][j + cst[i] + k]);
                    }
                    
                    else {
                        break;
                    }
                }
                
                if (DP[i][j] >= 0) {
                    DP[i + 1][j] = max(DP[i + 1][j], DP[i][j]);
                    ans = max(ans, DP[i + 1][j]);
                }
            }
        }
    }
    
    cout << ans << endl;
    return (0);
}