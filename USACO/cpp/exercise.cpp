#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <queue>
#include <math.h>
#include <string.h>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

typedef pair<long long, long long> ii;

vector<long long> con[MAX_N], con3[MAX_N];
vector<ii> con2[MAX_N];

bool vis[MAX_N];

long long d[MAX_N], lca[MAX_N][23], pre[MAX_N];
long long N, M, c, ans;

void DFS1 (int ind, int prev) {
    vis[ind] = true;
    
    lca[ind][0] = ind;
    lca[ind][1] = prev;
    
    d[ind] = d[prev] + 1;
    
    for (int i = 2; i < 23; i ++)
        lca[ind][i] = lca[lca[ind][i - 1]][i - 1];
    
    for (int i = 0; i < con[ind].size(); i ++)
        if (!vis[con[ind][i]])
            DFS1 (con[ind][i], ind);
            
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

void DFS2(int ind) {
    vis[ind] = true;
    
    for (int i = 0; i < con3[ind].size(); i ++) {
        pre[ind] ++;
        pre[con3[ind][i]] --;
    }
    
    for (int i = 0; i < con[ind].size(); i ++) {
        if (!vis[con[ind][i]]) {
            DFS2(con[ind][i]);
            pre[ind] += pre[con[ind][i]];
        }
    }
    
    ans += ((pre[ind]) * con2[ind].size());
    vis[ind] = false;
}

int main() {
    ifstream cin ("exercise.in");
    ofstream cout ("exercise.out");

    cin >> N >> M;

    long long a, b;
    for (long long i = 0; i < N - 1; i ++) {
        cin >> a >> b;
        a --;
        b --;

        con[a].push_back(b);
        con[b].push_back(a);
    }

    DFS1 (0, 0);
       
    for (long long i = 0; i < (M - N + 1); i ++) {
        cin >> a >> b;
        a --;
        b --;
        
        con2[LCA(a, b)].push_back(ii(a, b));
        con3[a].push_back(LCA(a, b));
        con3[b].push_back(LCA(a, b));
    }

    ans = 0;
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < con2[i].size(); j ++) {
            for (int k = j + 1; k < con2[i].size(); k ++) {
                if (LCA(con2[i][j].f, con2[i][k].f) != i || LCA(con2[i][j].f, con2[i][k].s) != i || 
                    LCA(con2[i][j].s, con2[i][k].f) != i || LCA(con2[i][j].s, con2[i][k].s) != i) {
                    ans ++;        
                }
            }
        }
    }
    
    DFS2(0);
     
    cout << ans << endl;
    return (0);
}