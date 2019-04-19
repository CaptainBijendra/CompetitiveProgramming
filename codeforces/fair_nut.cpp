#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define INF 2000000009
#define MAX_N 1000005
#define f first
#define s second

using namespace std;

typedef pair<long long, long long> ii;
vector<ii> con[MAX_N];

bool vis[MAX_N];

long long DP[MAX_N], val[MAX_N];
long long N, ans;

void DFS (long long ind) {
    vis[ind] = true;
    
    long long big = 0;
    
    for (long long i = 0; i < con[ind].size(); i ++) {
        if (!vis[con[ind][i].f]) {
            DFS (con[ind][i].f);
            ans = max(ans, big + max(0ll, DP[con[ind][i].f] - con[ind][i].s) + val[ind]);
            big = max(big, DP[con[ind][i].f] - con[ind][i].s);
        }
    }
    
    DP[ind] = big + val[ind];
    ans = max(ans, DP[ind]);
    
    vis[ind] = false;
}

int main() {
    cin >> N;

    for (long long i = 0; i < N; i ++)
        cin >> val[i];

    long long a, b, c;
    for (long long i = 0; i < N - 1; i ++) {
        cin >> a >> b >> c;
        con[a - 1].push_back(ii(b - 1, c));
        con[b - 1].push_back(ii(a - 1, c));
    }
    
    ans = 0;
    DFS(0);

    cout << ans << endl;
    return (0);
}