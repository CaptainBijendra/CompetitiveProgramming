#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];

int vis[MAX_N], vis2[MAX_N];
int P, C, N;

void DFS (int ind) {
    vis2[ind] = true;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        if (!vis2[con[ind][i]] && !vis[con[ind][i]]) {
            DFS (con[ind][i]);
        }
    }
}

int main() {
    cin >> P >> C >> N;
    
    int a, b;
    for (int i = 0; i < C; i ++) {
        cin >> a >> b;
        con[a - 1].push_back(b - 1);
        con[b - 1].push_back(a - 1);
    }       
    
    for (int i = 0; i < N; i ++) {
        cin >> a;
        
        for (int j = 0; j < con[a - 1].size(); j ++)
            vis[con[a - 1][j]] = true;
    }
    
    DFS (0);
    
    int ans = 0;
    for (int i = 0; i < P; i ++)
        ans += vis2[i];
    
    cout << (P - ans) << endl;
    return (0);
}