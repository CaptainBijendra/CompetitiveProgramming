#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 300005
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];

bool op[MAX_N], vis[MAX_N];

int N;

int DFS (int ind) {
    int ans;
    
    vis[ind] = true;
    
    if (con[ind].size() == 1 && ind != 0)
        return (1);
    
    if (op[ind])
        ans = MAX_N;
    else
        ans = 0;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        if (!vis[con[ind][i]]) {
            int x = DFS (con[ind][i]);
        
            if (op[ind]) { ans = min(ans, x); }
            else { ans += x; }
        }
    }
    
    return (ans);
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i ++)
        cin >> op[i];
        
    int x;
    for (int i = 1; i < N; i ++) {
        cin >> x; x --;
        
        con[i].push_back(x);
        con[x].push_back(i);
    }
    
    int leaves = 0;
    for (int i = 1; i < N; i ++)
        if (con[i].size() == 1)
            leaves ++;

    cout << leaves - DFS(0) + 1 << endl;
    return (0);
}