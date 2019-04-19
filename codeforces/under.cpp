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

bool vis[MAX_N];

int d[MAX_N], lca[MAX_N][23];
int N, Q;

void DFS (int ind, int prev) {
    vis[ind] = true;
    
    lca[ind][0] = ind;
    lca[ind][1] = prev;
    
    d[ind] = d[prev] + 1;
    
    for (int i = 2; i < 23; i ++)
        lca[ind][i] = lca[lca[ind][i - 1]][i - 1];
    
    for (int i = 0; i < con[ind].size(); i ++)
        if (!vis[con[ind][i]])
            DFS (con[ind][i], ind);
            
    vis[ind] = false;
}

int LCA (int a, int b) {
    int x = a;
    int y = b;
    
    if (d[x] > d[y]) {
        x = b;
        y = a;
    }
    
    for (int i = d[y] - d[x]; i > 0; i = (i & (i - 1))) { 
        y = lca[y][(int)(log2(i - (i & (i - 1)))) + 1];
    }
    
    if (x == y)
        return (x);
    
    for (int i = 22; i >= 0; i --) {
        if (lca[x][i] != lca[y][i]) {
            x = lca[x][i];
            y = lca[y][i];
        }
    }
    
    return (lca[x][1]);
}

int dist(int a, int b) {
    return (d[a] + d[b] - 2 * d[LCA(a, b)] + 1);
}

int main() {
    cin >> N >> Q;
    
    int a, b, c;
    for (int i = 1; i < N; i ++) {
        cin >> a; a --;
        con[i].push_back(a);
        con[a].push_back(i);
    }
    
    DFS(0, 0);
    
    int x;
    for (int i = 0; i < Q; i ++) {
        cin >> a >> b >> c;
        a --; b --; c --;
        
        x = LCA(a, b) ^ LCA(b, c) ^ LCA(a, c);
        cout << max(max(dist(x, a), dist(x, b)), dist(x, c)) << endl;
    }
    
    return (0);
}