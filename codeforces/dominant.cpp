#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <string.h>
#include <math.h>

#define MAX_N 1000005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

map<int, int> cnt;

vector<int> con[MAX_N];

bool blocked[MAX_N];

int summ[MAX_N], par[MAX_N], ans[MAX_N];
int N, L, W;

void DFS (int ind, int p) {
    summ[ind] = 1;
    par[ind] = p;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        if (par[ind] != con[ind][i] && !blocked[con[ind][i]]) {
            DFS(con[ind][i], ind);
            summ[ind] += summ[con[ind][i]];
        }
    }
}

void find_paths(int ind, int p, int d) {
    cnt[d] ++;
    
    for (int i = 0; i < con[ind].size(); i ++)
        if (!blocked[con[ind][i]] && p != con[ind][i]) {
            find_paths(con[ind][i], ind, d + 1);    
        }
}

void solve(int ind) {
    for (int i = 0; i < con[ind].size(); i ++)
        if (!blocked[con[ind][i]])
            find_paths(con[ind][i], ind, 0);
}

void centroid(int ind) {
    DFS (ind, ind);

    queue<int> q;
    q.push(ind);
    
    int centr = -1;
    int big = summ[ind];
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        int sz = summ[ind] - summ[cur];
        
        for (int i = 0; i < con[cur].size(); i ++) {
            if (par[cur] != con[cur][i] && !blocked[con[cur][i]]) {
                sz = max(sz, summ[con[cur][i]]);
                q.push(con[cur][i]);        
            }
        }
        
        if (sz < big) {
            big = sz;
            centr = cur;
        }
    }
    
    cnt.clear();
    //We found centroid, and we're going to call solve() method here
    //For different problems, this solve() method can change
    solve(centr);
    blocked[centr] = true;
    
    ans[ind] = MAX_N;
    
    for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it ++) {
        if (it->second > cnt[ans[ind]]) 
            ans[ind] = it->first;
        else if (it->second == cnt[ans[ind]])
            ans[ind] = min(ans[ind], it->first);
    
        cout << ind << " " << it->first << " " << it->second << endl;
    }
    
    for (int i = 0; i < con[centr].size(); i ++)
        if (!blocked[con[centr][i]])
            centroid(con[centr][i]);
}

int main() {
    cin >> N;
    
    int a, b;
    for (int i = 0; i < N - 1; i ++) {
        cin >> a >> b;
        con[a - 1].push_back(b - 1);
        con[b - 1].push_back(a - 1);
    }
    
    centroid(0);
    
    for (int i = 0; i < N; i ++)
        cout << ans[i] << endl;
    
    return (0);
}