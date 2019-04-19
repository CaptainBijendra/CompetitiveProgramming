#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#include <math.h>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];
vector<int> ans;

bool vis[MAX_N];

int sz[MAX_N], DP[MAX_N], par[MAX_N];
int N;

void DFS (int ind) {
    DP[ind] = 1;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        DFS (con[ind][i]);
        DP[ind] += DP[con[ind][i]];
    }
}


void DFS2 (int ind) {
    bool pos = true;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        if (DP[con[ind][i]] % 2 == 0) {
            pos = false;
            break;
        }
    }
    
    if (pos && sz[ind] % 2 == 0 && sz[ind] > 0) {
        vis[ind] = true;
        ans.push_back(ind);
        
        for (int i = 0; i < con[ind].size(); i ++)
            sz[con[ind][i]] --;
    
        sz[par[ind]] --;

        for (int i = 0; i < con[ind].size(); i ++)
            DFS2 (con[ind][i]);
    }
}

int main() {
    cin >> N;
    
    if (N % 2 == 0) {
        cout << "NO" << endl;
        return (0);
    }
    
    int x;
    int root;
    
    for (int i = 0; i < N; i ++) {
        cin >> x;    
        
        if (x > 0) {
            con[x - 1].push_back(i);
            par[i] = x - 1;
            
            sz[i] ++;
            sz[x - 1] ++;
        }
        
        else {
            root = i;
        }
    }
    
    DFS (root);
    DFS2 (root);
    
    for (int i = 0; i < N; i ++)
        if (!vis[i])
            ans.push_back(i);
    
    cout << "YES" << endl;
    
    for (int i = 0; i < ans.size(); i ++)
        cout << (ans[i] + 1) << endl;
    
    return (0);
}