#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

vector<ii> edges, sol;
vector<int> con[MAX_N];
vector<int> extra;

bool vis[MAX_N], use[MAX_N], use2[MAX_N];

int par[MAX_N], sz[MAX_N], fnd[MAX_N];
int N, M, D;

void init(int size) {
    for (int i = 0; i < size; i ++) {
        par[i] = i;
        sz[i] = 1;
    }
}

int find(int x) {
    while (x != par[x]) {
        par[x] = par[par[x]];
        x = par[x];
    }

    return (x);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y)
        return;

    if (sz[x] > sz[y]) {
        par[y] = x;
        sz[x] += sz[y];
    }

    else {
        par[x] = y;
        sz[y] += sz[x];
    }
}

void BFS (int ind) {
    queue<int> q;
    q.push(ind);
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        vis[cur] = true;
        for (int i = 0; i < con[cur].size(); i ++) {
            if (!vis[con[cur][i]]) {
                sol.push_back(ii(cur + 1, con[cur][i] + 1));

                vis[con[cur][i]] = true;
                q.push(con[cur][i]);
            }
        }
    }
}

int main() {
    cin >> N >> M >> D;
    
    int a, b;
    for (int i = 0; i < M; i ++) {
        cin >> a >> b; 
        a --; b --;
    
        if (a == 0)
            extra.push_back(b);
        else if (b == 0)
            extra.push_back(a);
    
        edges.push_back(ii(a, b));
    }
    
    init(MAX_N);
    
    for (int i = 0; i < edges.size(); i ++) {
        int c = edges[i].f;
        int v = edges[i].s;
        
        if (find(c) != find(v) && c != 0 && v != 0) {
            merge(c, v);
            con[c].push_back(v);
            con[v].push_back(c);
        }
    }
    
    for (int i = 0; i < extra.size(); i ++) {
        if (!use[find(extra[i])] && D > 0) {
            use[find(extra[i])] = true;
            use2[extra[i]] = true;
            con[0].push_back(extra[i]);
            D --;
        }
    }
    
    for (int i = 0; i < extra.size(); i ++) {
        if (D > 0 && !use2[extra[i]]) {
            con[0].push_back(extra[i]);          
            D --;
        } 
    }
    
    if (D > 0) {
        cout << "NO" << endl;
        return (0);
    }
    
    BFS (0);

    for (int i = 0; i < N; i ++)
        if (!vis[i]) {
            cout << "NO" << endl;
            return (0);
        }
    
    cout << "YES" << endl;
    
    for (int i = 0; i < sol.size(); i ++)
        cout << sol[i].f << " " << sol[i].s << endl;
            
    return (0);
}