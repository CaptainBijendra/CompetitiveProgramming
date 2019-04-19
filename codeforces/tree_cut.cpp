#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <math.h>
#include <string.h>

#define MAX_N 300005
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];

bool vis[MAX_N];

int red[MAX_N], blue[MAX_N];
int N, ans;

void DFS (int ind) {
    vis[ind] = true;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        if (!vis[con[ind][i]]) {
            DFS (con[ind][i]);
            red[ind] += red[con[ind][i]];
            blue[ind] += blue[con[ind][i]];
        }
    }
    
    vis[ind] = false;
}

void DFS2 (int ind) {
    vis[ind] = true;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        if (!vis[con[ind][i]]) {
            DFS2 (con[ind][i]);
            
            bool bot_red = (red[con[ind][i]] > 0);
            bool bot_blue = (blue[con[ind][i]] > 0);
            bool top_red = (red[0] - red[con[ind][i]] > 0);
            bool top_blue = (blue[0] - blue[con[ind][i]] > 0);
            
            if (!(bot_red && bot_blue) && !(top_red && top_blue))
                ans ++;
        }
    }
    
    vis[ind] = false;
}

int main() {
    cin >> N;
    
    int x;
    for (int i = 0; i < N; i ++) {
        cin >> x;
    
        if (x == 2)
            blue[i] = 1;
        if (x == 1)
            red[i] = 1;
    }
    
    int a, b;
    for (int i = 0; i < N - 1; i ++) {
        cin >> a >> b;
        a --; b --;
        
        con[a].push_back(b);
        con[b].push_back(a);
    }
    
    DFS (0);
    ans = 0;
    DFS2 (0);
    
    cout << ans << endl;
    return (0);
}