#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>

#define MOD 1000000007
#define MAX_N 10005
#define f first
#define s second

using namespace std;

typedef pair<long long, long long> ii;

ii cow[MAX_N];

long long DP[MAX_N], ans[MAX_N], cnt[256], DP2[MAX_N];
long long N, M, K;

long long fast_expo (long long base, long long pow) {
    if (pow == 1)
        return (base);
    if (pow == 0)
        return (1);
    
    if (pow % 2 == 0) {
        long long a = fast_expo(base, pow / 2);
        return ((a * a) % MOD);
    }
    
    else {
        long long a = fast_expo(base, (pow - 1) / 2);
        return ((((a * a) % MOD) * base) % MOD);
    }
}

int main() {
    ifstream fin ("poetry.in");
    ofstream fout ("poetry.out");
    
    fin >> N >> M >> K;
    
    for (long long i = 0; i < N; i ++)
        fin >> cow[i].f >> cow[i].s;
    
    DP[0] = 1;
    
    for (long long i = 0; i <= K; i ++) {
        for (long long j = 0; j < N; j ++) {
            DP[min(K, i + cow[j].f)] += DP[i];
            DP[min(K, i + cow[j].f)] %= MOD;
        }
    }
    
    for (long long i = 0; i < N; i ++) {
        if (K >= cow[i].f) {    
            ans[cow[i].s] += DP[K - cow[i].f];
            ans[cow[i].s] %= MOD;
        }
    }
    
    char let;
    
    for (long long j = 0; j < M; j ++) {
        fin >> let;
        cnt[let - 'A'] ++;
    }
    
    int nxt = 0;
    
    while (cnt[nxt] == 0)
        nxt ++;
    
    int prev = nxt;
    
    for (long long j = 0; j < MAX_N; j ++) {
        DP2[nxt] += fast_expo(ans[j], cnt[nxt]);
        DP2[nxt] %= MOD;
    }
    
    for (long long i = nxt + 1; i < 26; i ++) {
        if (cnt[i] == 0)
            continue;
        
        for (long long j = 0; j < MAX_N; j ++) {
            DP2[i] += ((DP2[prev] * fast_expo(ans[j], cnt[i])) % MOD);
            DP2[i] %= MOD;
        }
        
        prev = i;
    }
    
    fout << DP2[prev] << endl;
    return (0);
}