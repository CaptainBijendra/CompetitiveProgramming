#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <string.h>
#include <math.h>

#define INF 2000000009
#define MAX_N 200005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
priority_queue<ii> edges;

vector<int> con[MAX_N];
vector<ii> red[350], query[350];

int par[MAX_N][23], d[MAX_N], cost[MAX_N];
int N, M;

void DFS (int ind, int prev) {
    par[ind][0] = ind;
    par[ind][1] = prev;
    
    d[ind] = d[prev] + 1;
    
    for (int i = 2; i < 23; i ++) 
        par[ind][i] = par[par[ind][i - 1]][i - 1]; 
    
    for (int i = 0; i < con[ind].size(); i ++) 
        if (con[ind][i] != prev) 
            DFS(con[ind][i], ind);
}

int LCA (int a, int b) {
    int x = a;
    int y = b;
    
    if (d[x] > d[y]) {
        x = b;
        y = a;
    }
    
    for (int i = d[y] - d[x]; i > 0; i = (i & (i - 1))) { 
        y = par[y][(int)(log2(i - (i & (i - 1)))) + 1];
    }
    
    if (x == y)
        return (x);
    
    for (int i = 22; i >= 0; i --) {
        if (par[x][i] != par[y][i]) {
            x = par[x][i];
            y = par[y][i];
        }
    }
    
    return (par[x][1]);
}

int dist(int a, int b) {
    if (d[a] + d[b] - 2 * d[LCA(a, b)] < 0)
        return INF;
    
    return (d[a] + d[b] - 2 * d[LCA(a, b)]);
}

void BFS() {
    priority_queue<ii> tmp = edges;
    
    while (!tmp.empty()) {
        ii cur = tmp.top();
        tmp.pop();
        
        int u = cur.s;
        int cst = -1 * cur.f; 
        
        for (int i = 0; i < con[u].size(); i ++) {
            if (cost[con[u][i]] > cst + 1) { 
                cost[con[u][i]] = cst + 1;
                tmp.push(ii(-1 * (cst + 1), con[u][i]));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    
    int a, b;
    for (int i = 0; i < N - 1; i ++) {
        cin >> a >> b;
        con[a - 1].push_back(b - 1);
        con[b - 1].push_back(a - 1);
    }
    
    DFS(0, 0);
    
    int block_sz = (int)(sqrt(M));
    
    red[0].push_back(ii(-1, 0));
    
    for (int i = 0; i < M; i ++) {
        cin >> a >> b;
        b --;
        
        if (a == 1) 
            red[i / block_sz].push_back(ii(i, b));
        if (a == 2)
            query[i / block_sz].push_back(ii(i, b));
    }
    
    for (int i = 0; i < MAX_N; i ++)
        cost[i] = INF;
    
    int sweep = 0;

    for (int i = 0; i < ((M + block_sz - 1) / block_sz); i ++) { //sqrt(N);
        if (i != 0) {
            for (int j = 0; j < red[sweep].size(); j ++) { //sqrt(N);
                cost[red[sweep][j].s] = 0;
                
                for (int k = 0; k < con[red[sweep][j].s].size(); k ++) {
                    if (cost[con[red[sweep][j].s][k]] > 1) { 
                        cost[con[red[sweep][j].s][k]] = 1;
                        edges.push(ii(-1, con[red[sweep][j].s][k]));    
                    }
                }
            }
            
            BFS(); //NlogN
            sweep ++;
        }
        
        for (int j = 0; j < query[sweep].size(); j ++) { //sqrt(N);
            int small = INF;

            for (int k = 0; k < red[sweep].size(); k ++) //sqrt(N)
                if (red[sweep][k].f < query[sweep][j].f)
                    small = min(small, dist(query[sweep][j].s, red[sweep][k].s));
            
            cout << min(cost[query[sweep][j].s], small) << '\n';
        }
    }
    
    return (0);
}
