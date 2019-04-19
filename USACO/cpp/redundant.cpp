#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <string.h>
#include <math.h>

#define MAX_N 5005
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N], con2[MAX_N];
map<int, bool> rep[MAX_N];

bool visited[MAX_N];
bool bridge[MAX_N][MAX_N];

int vis[MAX_N], low[MAX_N], col[MAX_N];
int N, M, T;

void DFS (int ind, int parent) {
    visited[ind] = true;
    vis[ind] = T; low[ind] = T;
    T ++;
    
    int children = 0;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        if (con[ind][i] == parent)
            continue;
        
        if (visited[con[ind][i]])
            low[ind] = min(low[ind], vis[con[ind][i]]);
        else {
            DFS (con[ind][i], ind);
            low[ind] = min(low[ind], low[con[ind][i]]);
    
            if (low[con[ind][i]] > vis[ind]) {
                bridge[ind][con[ind][i]] = true;
                bridge[con[ind][i]][ind] = true;
            }
        }
    }
}

void DFS2(int ind, int c) {
    col[ind] = c;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        if (!bridge[ind][con[ind][i]] && !col[con[ind][i]]) {
            DFS2(con[ind][i], c);
        }
    }
}

int main() {
    cin >> N >> M;
    
    int a, b;
    for (int i = 0; i < M; i ++) {
        cin >> a >> b;
        
        con[a - 1].push_back(b - 1);
        con[b - 1].push_back(a - 1);
    }
    
    T = 0;
    
    for (int i = 0; i < N; i ++) {
        if (!visited[i])
            DFS (i, -1);
    }

    int c = 1;
    for (int i = 0; i < N; i ++) 
        if (!col[i]) {
            DFS2(i, c);
            c ++;
        }
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < con[i].size(); j ++) {
            if (col[i] != col[con[i][j]] && !rep[col[i]][col[con[i][j]]] && !rep[col[con[i][j]]][col[i]]) {
                con2[col[i]].push_back(col[con[i][j]]);
                con2[col[con[i][j]]].push_back(col[i]);
                
                rep[col[i]][col[con[i][j]]] = true;
                rep[col[con[i][j]]][col[i]] = true;
            }
        }
    }
    
    int leaves = 0;
    for (int i = 1; i < c; i ++) {
        leaves += (con2[i].size() == 1);
    }
    
    cout << (leaves / 2) + (leaves % 2) << endl;
    return (0);    
}