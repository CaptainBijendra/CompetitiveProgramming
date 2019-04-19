#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
#include <vector.h>

#define MAX_N 300005
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];

bool vis[MAX_N];

int dep[MAX_N];
int N, M;

void DFS (int ind) {
    vis[ind] = true;
    
    vector<int> pos;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        if (!vis[con[ind][i]]) {
            DFS (con[ind][i]);
            pos.push_back(dep[con[ind][i]] + 1);
        }
    }
    
    if (pos.size() > 0) { 
        sort(pos.begin(), pos.end());
    }
}

int main() {
    cin >> N >> M;
    
    int sm = MAX_N;
    
    for (int i = 0; i < N; i ++) {
        int a, b;
        
        cin >> a >> b;
        con[a - 1].push_back(b - 1);
        con[b - 1].push_back(a - 1);
        
        sm = min(sm, mn(a - 1, b - 1));
    }
    
    DFS (sm);
    
    return (0);
}