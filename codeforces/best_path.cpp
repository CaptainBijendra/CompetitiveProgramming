#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

#define MAX_N 300005
#define f first
#define s second

using namespace std;

typedef pair<long long, long long> ii;

vector<ii> con[MAX_N], con2[MAX_N];

bool vis[MAX_N];

long long par[MAX_N], C[MAX_N], DP[MAX_N];
long long N, ans = 0ll;

void DFS (long long ind, long long prev) {
    par[ind] = prev;
    
    for (long long i = 0; i < con[ind].size(); i ++)
        if (par[con[ind][i].f] == -1)
            DFS (con[ind][i].f, ind);
}

void DFS2 (long long ind) {
    vis[ind] = true;
    
    vector<long long> dist;
    
    for (long long i = 0; i < con2[ind].size(); i ++) {
        if (!vis[con2[ind][i].f]) {
            DFS2 (con2[ind][i].f);
            DP[ind] = max(DP[ind], DP[con2[ind][i].f] + con2[ind][i].s);
        
            dist.push_back(DP[con2[ind][i].f] + con2[ind][i].s);
        }
    }
    
    sort(dist.begin(), dist.end());
    
    if (dist.size() == 1)
        ans = max(ans, C[ind] + dist[0]);
    else if (dist.size() >= 2)
        ans = max(ans, C[ind] + max(0ll, dist[dist.size() - 1]) + max(0ll, dist[dist.size() - 2]));
}

int main() {
    cin >> N;
    
    for (long long i = 0; i < N; i ++) {
        cin >> C[i];
        ans = max(ans, C[i]);
        par[i] = -1;
    }
    
    long long a, b, c;
    for (long long i = 0; i < N - 1; i ++) {
        cin >> a >> b >> c;
    
        con[a - 1].push_back(ii(b - 1, c));
        con[b - 1].push_back(ii(a - 1, c));
    }
    
    DFS (0, 0);
    
    for (long long i = 1; i < N; i ++) {
        for (long long j = 0; j < con[i].size(); j ++)
            if (con[i][j].f == par[i])
                con2[par[i]].push_back(ii(i, C[i] - con[i][j].s));
    }
    
    DFS2 (0);
    
    cout << ans << endl;
    return (0);
}