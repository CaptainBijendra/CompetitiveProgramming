#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 55
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, ii> pii;

vector<pii> vc;

int con[MAX_N][MAX_N][MAX_N];

int DP[MAX_N][MAX_N][MAX_N], big_dp[MAX_N][MAX_N][MAX_N];
int trans[MAX_N][MAX_N], sub[MAX_N];

int N, H, M;

int main() {
    cin >> N >> H >> M;
    
    int x, y, z, a;
    for (int i = 0; i < M; i ++) {
        cin >> x >> y >> z >> a;
        con[x - 1][y - 1][z] += a;
        
        vc.push_back(pii(ii(x - 1, y - 1), ii(z, a)));
    }
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j <= H; j ++) {
            DP[i][i][j] = j * j;
            
            for (int k = 0; k < j; k ++)
                DP[i][i][j] -= con[i][i][k];

            DP[i][i][j] = max(0, DP[i][i][j]);
        }
        
        big_dp[i][i][0] = DP[i][i][0];
            
        for (int k = 1; k <= H; k ++)
            big_dp[i][i][k] = max(DP[i][i][k], big_dp[i][i][k - 1]);
    }

    for (int len = 2; len <= N; len ++) {
        for (int i = 0; i < N; i ++) {
            int j = (i + len) - 1;
            
            if (j >= N)
                break;
            
            for (int k = 0; k <= H; k ++)
                for (int l = 0; l < N; l ++) {
                    trans[l][k] = 0;
                    sub[l] = 0;
                }
            
            for (int k = i; k < j; k ++) {
                for (int l = 0; l < M; l ++) {
                    if (vc[l].f.f >= i && vc[l].f.f <= k && vc[l].f.s >= k + 1 && vc[l].f.s <= j)
                        trans[k][vc[l].s.f + 1] += vc[l].s.s;        
                }
            }
            
            for (int k = 0; k <= H; k ++) {
                for (int split = i; split < j; split ++) {
                    sub[split] += trans[split][k];
                    DP[i][j][k] = max(DP[i][j][k], max(DP[i][split][k] + big_dp[split + 1][j][k], big_dp[i][split][k] + DP[split + 1][j][k]) - sub[split]);
                }        
            }
            
            big_dp[i][j][0] = max(0, DP[i][j][0]);
            for (int k = 1; k <= H; k ++)
                big_dp[i][j][k] = max(DP[i][j][k], big_dp[i][j][k - 1]);
        }
    }
    
    cout << big_dp[0][N - 1][H] << endl;
    return (0);
}