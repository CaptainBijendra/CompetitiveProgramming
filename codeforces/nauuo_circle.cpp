#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_N 200005
#define MOD 998244353 
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];

bool vis[MAX_N];

long long DP[MAX_N], fact[MAX_N];
long long N;

void DFS (int ind) {
    vis[ind] = true;
    
    long long mult = 1ll;
    for (int i = 0; i < con[ind].size(); i ++) {
        if (!vis[con[ind][i]]) {
            DFS (con[ind][i]);
            mult = (mult * DP[con[ind][i]]) % MOD;
        }    
    }
    
    DP[ind] = (DP[ind] * mult) % MOD;
    DP[ind] = (DP[ind] * fact[con[ind].size()]) % MOD;
}

int main() {
    cin >> N;
    
    int a, b;
    for (int i = 0; i < N - 1; i ++) {
        cin >> a >> b;
        a --; b --;
        
        con[a].push_back(b);
        con[b].push_back(a);
        
        DP[i] = 1ll;
    }
    
    fact[0] = 1ll;
    for (int i = 1; i < MAX_N; i ++)
        fact[i] = (fact[i - 1] * i) % MOD;
    
    DP[N - 1] = 1ll;
    DFS (0);
    
    cout << ((DP[0] * (long long)N) % MOD) << endl;
    return (0);
}