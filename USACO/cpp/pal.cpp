#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

#define MAX_N 205
#define MOD 1000000007

using namespace std;

int DP[MAX_N][MAX_N][MAX_N][105];

string str;
int ar[MAX_N], fact[MAX_N];
int N;

int main() {
    cin >> N;
    cin >> str;
    
    for (int i = 0; i < N; i ++)
        ar[i] = str[i] - '0';
    
    fact[0] = 1;
    
    for (int i = 1; i <= N; i ++) {
        fact[i] = fact[i - 1] * 10;
        fact[i] %= 101;
    }
    
    for (int i = 0; i < N; i ++)
        for (int j = i; j < N; j ++) 
            for (int k = i; k <= j; k ++) 
                DP[i][j][1][ar[k]] ++;
    
    for (int i = 0; i < N; i ++)
        for (int j = 0; j < N; j ++) 
            DP[i][j][0][0] ++;
    
    for (int len = 1; len < N; len ++) {
        for (int i = 0; i < N; i ++) {
            int j = i + len;
            
            if (j >= N)
                break;
            
            for (int k = 2; k <= N; k ++) {
                for (int l = 0; l < 101; l ++) {
                    int nxt_mod = (ar[i] * fact[k - 1] + l * 10 + ar[j]) % 101;
                    
                    if (ar[i] == ar[j]) {
                        DP[i][j][k][nxt_mod] += DP[i + 1][j - 1][k - 2][l];
                        DP[i][j][k][nxt_mod] %= MOD;
                    }
                    
                    DP[i][j][k][l] += DP[i + 1][j][k][l];
                    DP[i][j][k][l] %= MOD;

                    DP[i][j][k][l] += DP[i][j - 1][k][l];
                    DP[i][j][k][l] %= MOD;

                    DP[i][j][k][l] -= DP[i + 1][j - 1][k][l];
                    DP[i][j][k][l] = (DP[i][j][k][l] + MOD) % MOD;
                }    
            }
        }
    }
    
    int ans = 0;
    
    for (int i = 1; i <= N; i ++) {
        ans += DP[0][N - 1][i][0];
        ans %= MOD;
    }
    
    cout << ans << endl;
    return 0;
}

