#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define MAX_M 100005

using namespace std;

vector<int> con[MAX_N];
vector<int> centroid;

bool vis[MAX_N];

int sub[MAX_N];
int N, M;

void DFS (int ind) {
    sub[ind] = 1;   
    
    if (con[ind].size() == 1)
        return;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        if (!sub[con[ind][i]]) {
            DFS (con[ind][i]);
            sub[ind] += sub[con[ind][i]];
        }
    }
}

void DFS_cent(int ind) {
    if (con[ind].size() == 1)
        return;
    
    vis[ind] = true;
    
    bool pos = (N - sub[ind] <= (N / 2));
    
    for (int i = 0; i < con[ind].size(); i ++) {
        if (sub[con[ind][i]] > (N / 2) && !vis[con[ind][i]])
            DFS_cent([con[ind][i]]);
    }

    if (pos)

    vis[ind] = false;
}

int main() {
    cin >> N >> M;
    
    int a, b;
    for (int i = 0; i < N; i ++) {
        cin >> a >> b;
    
        con[a - 1].push_back(b - 1);
        con[b - 1].push_back(a - 1);
    }
    
    DFS (0);
    DFS_cent(0);
    
    
    return (0);
}