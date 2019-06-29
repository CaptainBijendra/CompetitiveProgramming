#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];

bool vis[MAX_N];

int sz[MAX_N], DP[MAX_N];
int N;

long long ans = 0ll;

void DFS (int ind) {
    sz[ind] = 1;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        if (!sz[con[ind][i]]) {
            DFS (con[ind][i]);
            sz[ind] += sz[con[ind][i]];
        
            int nxt = con[ind][i];
            for (int j = 0; j < con[nxt].size(); j ++) {
                if (con[nxt][j] == ind) { continue; }
                DP[ind] += (sz[con[nxt][j]] + DP[con[nxt][j]]);
            }
            
            DP[ind] ++;
        }
    }
}

void DFS2 (int ind) {
    vis[ind] = true;
    
    long long sum_sz = 0ll;
    long long sum_dp = 0ll;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        if (!vis[con[ind][i]]) {
            sum_sz += sz[con[ind][i]];
            sum_dp += DP[con[ind][i]];
        }
    }
    
    ans += DP[ind];
    
    for (int i = 0; i < con[ind].size(); i ++) {
        if (!vis[con[ind][i]]) {
            ans += ((sum_dp - DP[con[ind][i]]) * sz[con[ind][i]] + (sum_sz - sz[con[ind][i]]) * DP[con[ind][i]]);
            DFS2 (con[ind][i]);
        }
    }
}

int main() {
    cin >> N;
    
    int a, b;
    for (int i = 0; i < N - 1; i ++) {
        cin >> a >> b;
        con[a - 1].push_back(b - 1);
        con[b - 1].push_back(a - 1);
    }
    
    DFS (0);
    DFS2 (0);
    
    cout << ans << endl;
    return (0);
}