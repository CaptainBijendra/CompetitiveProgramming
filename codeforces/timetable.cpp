#include <iostream>

#define INF 200000000
#define MAX_N 505

using namespace std;

bool tt[MAX_N][MAX_N];

int pre[MAX_N]; 

int DP[MAX_N][MAX_N], mn[MAX_N][MAX_N];
int N, M, K;

int main() {
    cin >> N >> M >> K;
    
    string st;
    
    for (int i = 0; i < N; i ++) {
        cin >> st;
        
        for (int j = 0; j < M; j ++)
        { tt[i][j] = (st[j] == '1'); }
    }
    
    for (int i = 0; i < N; i ++) {
        pre[0] = tt[i][0];

        for (int j = 0; j <= K; j ++) 
        { DP[i][j] = INF; mn[i][j] = INF; }
        
        for (int j = 0; j < M; j ++) { pre[j + 1] = pre[j] + tt[i][j + 1]; } mn[i][pre[M]] = 0;
        for (int j = 0; j < M; j ++) {
            for (int k = j; k < M; k ++) {
                int l = pre[M] - (pre[k] - pre[j - 1]);
                mn[i][l] = min(mn[i][l], k - j + 1);
            }
        }
    }
    
    for (int i = 0; i <= K; i ++)
    { DP[0][i] = mn[0][i]; }

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j <= K; j ++) {
            for (int k = 0; k <= (K - j); k ++) {
                DP[i + 1][j + k] = min(DP[i + 1][j + k], DP[i][j] + mn[i + 1][k]);
            }
        }
    }
    
    if (DP[N - 1][K] == INF) { cout << 0 << endl; }
    else { cout << DP[N - 1][K] << endl; }
    
    return (0);
}