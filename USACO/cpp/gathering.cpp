#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];

bool vis[MAX_N];

int val[MAX_N], lca[MAX_N][23], d[MAX_N];
int N, M;

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

void DFS1 (int ind) {
    for (int i = 0; i < con[ind].size(); i ++) {
        if (con[ind][i] != lca[ind][1]) {
            DFS1 (con[ind][i]); 
            
            if (val[con[ind][i]] == -1)
                val[ind] = -1;
        }
    }
    
    if (val[ind] != -1)
        return;
    
    bool pos = false;
    for (int i = 0; i < con[ind].size(); i ++) {
        if (con[ind][i] != lca[ind][1]) {
            if (val[con[ind][i]] == 2) {
                pos = true;
                break;
            }
        }
    }
    
    if (pos)
        return;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        if (con[ind][i] != lca[ind][1]) {
            if (val[con[ind][i]] == 0)
                val[con[ind][i]] = 1;
        }
    }
}

void DFS2 (int ind) {
    for (int i = 0; i < con[ind].size(); i ++) {
        if (con[ind][i] != lca[ind][1]) {
            if (val[ind] == 1)
                val[con[ind][i]] = 1;
            
            DFS2(con[ind][i]);
        }
    }
}

void finish() {
    ifstream fin ("gathering.in");
    ofstream fout ("gathering.out");
    
    for (int i = 0; i < N; i ++)
        fout << 0 << endl;
}

int main() {
    ifstream fin ("gathering.in");
    ofstream fout ("gathering.out");
    
    fin >> N >> M;    
    
    int a, b;
    for (int i = 0; i < N - 1; i ++) {
        fin >> a >> b;
        con[a - 1].push_back(b - 1);
        con[b - 1].push_back(a - 1);
    }

    DFS(0, 0);
    
    for (int i = 0; i < M; i ++) {
        fin >> a >> b; a --; b --;
        
        if (LCA(a, b) == a) {
            val[a] = -1;
            
            for (int i = 0; i < con[a].size(); i ++) {
                if (con[a][i] != lca[a][1] && LCA(con[a][i], b) != con[a][i])
                    val[con[a][i]] = 1;
            
                if (con[a][i] != lca[a][1] && LCA(con[a][i], b) == con[a][i]) {
                    if (val[con[a][i]] == 1) {
                        finish();
                        return (0);
                    }
                    
                    val[con[a][i]] = 2;
                }
            }
        }
        
        else 
            val[a] = 1;
    }   
    
    DFS1 (0);
    DFS2 (0); 
    DFS2 (0);
    
    for (int i = 0; i < N; i ++) {
        if (val[i] == 0 || val[i] == 2)
            fout << 1 << endl;
        else
            fout << 0 << endl;
    }
    return (0);
}