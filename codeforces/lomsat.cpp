#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

vector<int> con[MAX_N];

bool vis[MAX_N];

int C[MAX_N], sz[MAX_N], st[MAX_N], ans[MAX_N];
int N;

set<ii> DFS (int ind) {
    vis[ind] = true;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        if (!vis[con[ind][i]]) {
            DFS (con[ind][i]);

        }
    }
    
    seg.update(st[ind], C[ind]);
    ans[ind] = seg.query(st[ind], st[ind] + sz[ind] - 1);
} 

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i ++)
        cin >> C[i];
    
    int a, b;
    for (int i = 0; i < N - 1; i ++) {
        cin >> a >> b;
        a --; b --;
        
        con[a].push_back(b);
        con[b].push_back(a);
    }
    
    DFS (0);
    
    for (int i = 0; i < N; i ++)
        cout << ans[i] << " ";
    
    cout << endl;
    return (0);
}