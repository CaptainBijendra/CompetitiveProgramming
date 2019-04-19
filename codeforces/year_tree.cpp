#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 405
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];

bool vis[MAX_N];

int ord[MAX_N], col[MAX_N], L[MAX_N], R[MAX_N], sub[MAX_N];
int N, M, cnt;

void DFS (int ind) {
    vis[ind] = true;
    sub[ind] = 1;
    
    for (int i = 0; i < con[ind].size(); i ++)
        if (!vis[con[ind][i]]) {
            DFS(con[ind][i]);
            sub[ind] += sub[con[ind][i]];
        }
    
    L[ind] = cnt - sub[ind];
    R[ind] = cnt - 1;
    
    ord[ind] = cnt;
    cnt ++;
}

int main() {
    cin >> N >> M;
    
    for (int i = 0; i < N; i ++)
        cin >> col[i];
    
    int a, b;
    for (int i = 0; i < N - 1; i ++) {
        cin >> a >> b;
        con[a - 1].push_back(b - 1);
        con[b - 1].push_back(a - 1);
    }
    
    cnt = 0;
    DFS(0);
    
    for (int i = 0; i < N; i ++) {
        cout << ord[i] << endl;
    }
    
    return (0);
}