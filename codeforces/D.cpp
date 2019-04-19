#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

vector<int> con[MAX_N];
vector<ii> pos;

int ar[MAX_N], vis[MAX_N], sz[MAX_N], sub[MAX_N], ans[MAX_N];
int N, bot;

void DFS (int ind) {
    vis[ind] = true;
    sub[ind] = 1;
    
    if (con[ind].size() == 1 && ind != 0) {
        sz[ind] = 1;
        bot ++;
    }

    for (int i = 0; i < con[ind].size(); i ++) {
        if (!vis[con[ind][i]]) {
            DFS (con[ind][i]);
            sz[ind] += sz[con[ind][i]];
            sub[ind] += sub[con[ind][i]];
        } 
    }
    
    vis[ind] = false;
}

void DFS2 (int ind) {
    vis[ind] = true;   
    ans[sz[ind]] ++;

    for (int i = 0; i < con[ind].size(); i ++) {
        if (!vis[con[ind][i]]) {
            DFS2 (con[ind][i]);
        }
    }

    vis[ind] = false;
}

int main() {
    cin >> N;
    
    if (N == 1) {
        cout << 1 << endl;
        return (0);
    }

    int a, b;
    for (int i = 1; i < N; i ++) {
        cin >> a;
        
        con[i].push_back(a - 1);
        con[a - 1].push_back(i);
    }    

    bot = 0;
    DFS (0);
    DFS2 (0);    
    
    for (int i = 1; i <= N; i ++)
        ans[i + 1] += ans[i];
    
    int cnt = 0;
    for (int i = 1; i <= N; i ++) {
        while (cnt < ans[i]) {
            cout << i << " ";
            cnt ++;
        }
    }

    while (cnt < N)
        cout << bot << endl;

    cout << endl;
    return (0);
}
