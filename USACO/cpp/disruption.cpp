
#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string.h>
#include <math.h>

#define INF 2000000009
#define MAX_N 50005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

map<int, int> node[MAX_N];

vector<int> con[MAX_N], rem[MAX_N], vals[MAX_N];

bool vis[MAX_N];

int lca[MAX_N][23], d[MAX_N];
int ans[MAX_N];

int N, M;

void DFS1 (int ind, int prev) {
    vis[ind] = true;
    d[ind] = d[prev] + 1;
    
    lca[ind][0] = ind;
    lca[ind][1] = prev;
    
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

void DFS (int ind) {
    vis[ind] = true;
                
    for (int i = 0; i < con[ind].size(); i ++) {
        if (!vis[con[ind][i]]) {
            DFS (con[ind][i]);
            
            int start = con[ind][i];
            int destination = ind;
            
            if (node[con[ind][i]].size() > node[ind].size())
                swap(start, destination);
            
            //Merge smaller to larger (start -> destination)
            for (auto p : node[start]) {
                int occurances = p.s;
                int edge_weight = p.f;
                
                node[destination][edge_weight] += occurances;
            }
            
            node[start].clear();
            
            if (destination != ind)
                node[ind].swap(node[destination]);
        }
    }
    
    for (int i = 0; i < vals[ind].size(); i ++)
        node[ind][vals[ind][i]] ++;
    
    for (int i = 0; i < rem[ind].size(); i ++) {
        node[ind][rem[ind][i]] -= 2;
    
        if (node[ind][rem[ind][i]] == 0)
            node[ind].erase(rem[ind][i]);
    }

    ans[ind] = node[ind].begin()->first;
    ans[ind] = (ans[ind] == 0 ? -1 : ans[ind]);
    
    vis[ind] = false;
}

int main() {
    ifstream fin ("disruption.in");
    ofstream fout ("disruption.out");
    
    fin >> N >> M;
    
    vector<ii> answer;
    
    int a, b, w;
    for (int i = 0; i < N - 1; i ++) {
        fin >> a >> b;
        a --; b --;
    
        con[a].push_back(b);
        con[b].push_back(a);
        
        answer.push_back(ii(a, b));
    }
    
    DFS1(0, 0);
    
    for (int i = 0; i < M; i ++) {
        fin >> a >> b >> w;
        a --; b --;
        
        vals[a].push_back(w);
        vals[b].push_back(w);
        
        rem[LCA(a, b)].push_back(w);
    }
    
    DFS (0);
    
    for (int i = 0; i < answer.size(); i ++) {
        a = answer[i].f;
        b = answer[i].s;
        
        if (d[a] > d[b])
            fout << ans[a] << endl;
        else
            fout << ans[b] << endl;
    }
    
    return (0);
}