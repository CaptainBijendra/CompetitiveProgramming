#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];

int DP[MAX_N][2][2], vis[MAX_N], dep[MAX_N];
int N;

void DFS (int ind) {
    if (con[ind].size() == 1 && ind != 0) {
        DP[ind][0][0] = 0;
        DP[ind][0][1] = INF;
        DP[ind][1] = 1;
        DP[ind][1] = 1;
        
        return;
    }
    
    vis[ind] = true;
        
    int sum1 = 0;
    int sum2 = 0;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        if (!vis[con[ind][i]]) {
            dep[con[ind][i]] = dep[ind] + 1;
            DFS (con[ind][i]);
        
            sum1 += min(DP[con[ind][i]][0], DP[con[ind][i]][1]);
            sum2 += DP[con[ind][i]][1];
        }
    }
    
    DP[ind][0][0] = sum2;
    DP[ind][1] = sum1 + 1;
        
    vis[ind] = false;
}

int main() {
    cin >> N;
    
    int a, b;
    for (int i = 0; i < N - 1; i ++) {
        cin >> a >> b;
        a --; b --;
        
        con[a].push_back(b);
        con[b].push_back(a);
    }
    
    dep[0] = 1;
    DFS (0);
    
    int ans = 0;
    for (int i = 0; i < N; i ++) {
        if (dep[i] == 4) {
            if (con[i].size() == 1)
                ans += DP[i][1];
            else
                ans += min(DP[i][0], DP[i][1]);
        }        
    }
    
    int ans2 = 0;
    
    for (int i = 0; i < N; i ++) {
        if (dep[i] == 3)
            ans2 += min(DP[i][0], DP[i][1]);
    }
    
    cout << min(ans, ans2) << endl;
    return (0);
}