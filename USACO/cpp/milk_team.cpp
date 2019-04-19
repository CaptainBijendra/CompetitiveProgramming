#include <iostream>
#include <algorithm>
#include <fstream>
#include <queue>
#include <string.h>
#include <vector>
#include <math.h>

#define INF 200000009
#define MAX_N 505
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];

bool vis[MAX_N];

int DP[MAX_N][MAX_N][2], val[MAX_N], ans[MAX_N];
int N, X;

void DFS (int ind) {
    vis[ind] = true;
    
    vector<int> pos1 (MAX_N);
    vector<int> pos2 (MAX_N);
    
    for (int i = 1; i < MAX_N; i ++) {
        pos1[i] = -INF;
        pos2[i] = -INF;
    }
    
    for (int i = 0; i < con[ind].size(); i ++) {
        if (!vis[con[ind][i]]) {
            DFS (con[ind][i]);
            
            for (int k = MAX_N - 1; k >= 0; k --) {
                for (int j = MAX_N - k - 2; j >= 0; j --) {
                    pos1[k + j + 1] = max(pos1[k + j + 1], pos1[k] + DP[con[ind][i]][j][1]);
                    pos1[k + j] = max(pos1[k + j], pos1[k] + DP[con[ind][i]][j][0]);
                    pos2[k + j] = max(pos2[k + j], pos2[k] + max(DP[con[ind][i]][j][1], DP[con[ind][i]][j][0]));
                }
            }
        }
    }
    
    for (int i = 0; i < MAX_N; i ++) {
        DP[ind][i][0] = max(DP[ind][i][0], pos2[i]);
        DP[ind][i][1] = max(DP[ind][i][1], pos1[i] + val[ind]);
    }        
}

int main() {
    cin >> N >> X;
    
    for (int i = 0; i < MAX_N; i ++)
        for (int j = 0; j < MAX_N; j ++) {
            DP[i][j][0] = -INF;
            DP[i][j][1] = -INF;
        }   
    
    int x;
    for (int i = 0; i < N; i ++) {
        cin >> val[i] >> x;
        
        DP[i][0][1] = val[i];
        DP[i][0][0] = 0;        

        if (x == 0)
            continue;
        else {
            con[x - 1].push_back(i);
            con[i].push_back(x - 1);
        }        
    }
    
    vector<int> roots;
    
    for (int i = 0; i < N; i ++) {
        if (!vis[i]) {
            DFS (i);
            roots.push_back(i);
        }
    }
    
    for (int i = 1; i < MAX_N; i ++)
        ans[i] = -INF;
    
    for (int i = 0; i < roots.size(); i ++) {
        for (int j = MAX_N - 1; j >= 0; j --) {
            for (int k = MAX_N - j - 2; k >= 0; k --)
                ans[j + k] = max(ans[j + k], ans[j] + max(DP[roots[i]][k][0], DP[roots[i]][k][1]));
        }
    }
    
    for (int i = MAX_N - 1; i >= 0; i --)
        if (ans[i] >= X) {
            cout << i << endl;
            return (0);
        }

    cout << "-1" << endl;
    return (0);
}