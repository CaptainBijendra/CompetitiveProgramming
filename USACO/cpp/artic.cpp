#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];

bool visited[MAX_N];
bool articulation[MAX_N];

int vis[MAX_N], low[MAX_N];
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
    
            if (low[con[ind][i]] >= vis[ind] && parent != -1) {
                articulation[ind] = true;
            }

            children ++;
        }
    }
    
    if (parent == -1 && children > 1)
        articulation[ind] = true;
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
    
    int cnt = 0;
    for (int i = 0; i < MAX_N; i ++) {
        cnt += articulation[i];
    }
    
    cout << (cnt) << endl;
    return (0);    
}