#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h> 

#define MOD 1000000007
#define MAX_N 5005
#define f first 
#define s second

using namespace std;

unordered_map<long long, bool> vis;

string str;

long long hsh[MAX_N], powr[MAX_N], DP[MAX_N];
long long N, A, B;

void build_hash() {
    powr[0] = 1ll;
    hsh[0] = (str[0] - 'a' + 1ll);
    
    for (long long i = 1; i < N; i ++) {
        powr[i] = (powr[i - 1] * 79) % MOD;
        hsh[i] = (hsh[i - 1] * 79 + (str[i] - 'a' + 1)) % MOD;
    }        
}

long long sub(long long i, long long j) {
    return ((((hsh[j] - (i == 0 ? 0 : hsh[i - 1]) * powr[j - i + 1]) + MOD) % MOD + MOD) % MOD);
}

int main() {
    cin >> N >> A >> B;
    cin >> str;
    
    build_hash();
    
    for (int i = 1; i <= N; i ++)
        DP[i] = MOD;
    
    for (int i = 0; i < N; i ++) {
        DP[i + 1] = min(DP[i + 1], DP[i] + A);
        
        for (int j = i; j <= min(N - 1, (long long)(2 * i)); j ++) {
            if (vis[sub(i, j)])
                DP[j + 1] = min(DP[j + 1], DP[i] + B);
            else
                break;
        }
        
        for (int j = 0; j <= i; j ++)
            vis[sub(j, i)] = true;
    }
 
    cout << DP[N] << endl;   
    return (0);
}