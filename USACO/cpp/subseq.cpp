#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>

#define MOD 998244353
#define MAX_N 1005
#define f first
#define s second

using namespace std;

long long ar[MAX_N], choose[MAX_N][MAX_N], DP[MAX_N];
long long N;

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i ++)
        cin >> ar[i];
    
    for (int i = 0; i < MAX_N; i ++) 
        choose[i][0] = 1;
        
    for (int i = 0; i < MAX_N - 1; i ++) {
        for (int j = 0; j < MAX_N - 1; j ++) {
            choose[i + 1][j + 1] = choose[i][j + 1] + choose[i][j];
            choose[i + 1][j + 1] %= MOD;
        }
    }
    
    DP[N] = 1;
    
    long long ans = 0;
    
    for (int i = N - 2; i >= 0; i --) {
        if (ar[i] <= 0 || i + ar[i] >= N)
            continue;
        
        for (int j = (i + ar[i] + 1); j <= N; j ++) {
            DP[i] += choose[j - i - 1][ar[i]] * DP[j];
            DP[i] %= MOD;
        }
        
        ans += DP[i];
        ans %= MOD;
    }
    
    cout << ans << endl;
    return (0);
}