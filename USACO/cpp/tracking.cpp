
#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>

#define MOD 1000000007
#define MAX_N 200005
#define f first
#define s second

using namespace std;

long long ar[MAX_N], DP[MAX_N], sum_dp[MAX_N];
long long N, K;

long long sq(long long a) {
    return ((a * a) % MOD);
}

long long fast_pow(long long base, long long power) {
    if (power == 0)
        return 1ll;
    
    if (power % 2 == 0)
        return (sq(fast_pow(base, power / 2)) % MOD);
    
    return (((sq(fast_pow(base, power / 2)) % MOD) * base) % MOD);
}

long long solve(long long l, long long r, long long x) {
    if (l > r)
        return (1);
    
    for (int i = l; i <= r; i ++)
        DP[i] = 0;
    
    DP[l] = 1;
    
    for (int i = l + 1; i <= (r + 1); i ++) {
        if (i - K + 1 <= l) {
            DP[i] += fast_pow(x, i - l);
            DP[i] %= MOD;
        }
        
        DP[i] += ((DP[i - 1]) * (x + 1)) % MOD;
        DP[i] -= (((DP[max(l, i - K - 1)] * fast_pow(x, (i - K - 1 < l ? (i - l): K)))) % MOD);
        DP[i] =  ((DP[i] + MOD) % MOD + MOD) % MOD;
    }
    
    return (DP[(r + 1)]);
}

int main() {
    ifstream fin ("tracking2.in");
    ofstream fout ("tracking2.out");
    
    fin >> N >> K;
    
    for (long long i = 0; i < N - K + 1; i ++)
        fin >> ar[i];
    
    long long pre = 0;
    long long ans = 1ll;
    
    for (long long i = 1; i < N - K + 1; i ++) {
        if (ar[i] > ar[i - 1]) {
            if (pre < (i - 1)) {
                ans = (ans * solve(pre, i - 2, 1000000000ll - ar[i - 1])) % MOD;
                ans %= MOD;
            }
            
            pre = i;
        }
        
        if (ar[i] == ar[i - 1])
            continue;
        
        if (ar[i] < ar[i - 1]) {
            ans = (ans * solve(pre, i + K - 2, 1000000000ll - ar[i - 1])) % MOD;
            ans %= MOD;
            
            pre = i + K; 
        }
    }
    
    ans = (ans * solve(pre, N - 1, 1000000000ll - ar[N - K])) % MOD;
    ans %= MOD;
    
    fout << ans << endl;
    return (0);    
}