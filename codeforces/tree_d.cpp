#include <iostream>
#include <fstream>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 50005
#define MAX_K 505

using namespace std;

vector<int> con[MAX_N];

long double ans;

bool vis[MAX_N];

int DP[MAX_N][MAX_K];
int N, K;

void DFS (int ind) {
    vis[ind] = true;
    
    for (int i = 0; i < con[ind].size(); i ++)
        if (!vis[con[ind][i]])
            DFS (con[ind][i]);
        
    DP[ind][0] = 1;    
    
    for (int i = 0; i < con[ind].size(); i ++)
        for (int j = 1; j < MAX_K; j ++)
            DP[ind][j] += DP[con[ind][i]][j - 1];
    
    vis[ind] = false;
}

void DFS2 (int ind) {
    vis[ind] = true;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        if (!vis[con[ind][i]])
            for (int j = 1; j <= K - 1; j ++) 
                ans += ((DP[con[ind][i]][j - 1] * (DP[ind][K - j] - DP[con[ind][i]][K - j - 1]))) * 0.5;
    }
    
    ans += DP[ind][K];
    
    for (int i = 0; i < con[ind].size(); i ++) 
        if (!vis[con[ind][i]])
            DFS2(con[ind][i]);
    
    vis[ind] = false;
}

int main() {
    cin >> N >> K;
    
    int a, b;
    for (int i = 0; i < N - 1; i ++) {
        cin >> a >> b;
        con[a - 1].push_back(b - 1);
        con[b - 1].push_back(a - 1);
    }

    ans = 0.0;
    DFS(0);
    DFS2(0);
    
    cout << (long long)(ans) << endl;
    return (0);    
}