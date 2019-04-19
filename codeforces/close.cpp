#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

vector<ii> con[MAX_N];
vector<ii> paths;

bool blocked[MAX_N];

int summ[MAX_N], par[MAX_N];
int N, L, W;

void DFS (int ind, int p) {
    summ[ind] = 1;
    par[ind] = p;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        if (par[ind] != con[ind][i].f && !blocked[con[ind][i].f]) {
            DFS(con[ind][i].f, ind);
            summ[ind] += summ[con[ind][i].f];
        }
    }
}

void find_paths(int ind, int p, int sum, int d) {
    paths.push_back(ii(d, sum));

    for (int i = 0; i < con[ind].size(); i ++)
        if (!blocked[con[ind][i].f] && p != con[ind][i].f) {
            if (d + 1 <= L && sum + con[ind][i].s <= W)
                find_paths(con[ind][i].f, ind, sum + con[ind][i].s, d + 1);    
        }
}

long long solve(int ind) {
    long long result = 0ll;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        if (!blocked[con[ind][i].f]) {
            find_paths(con[ind][i].f, ind, con[ind][i].s, 1);
            
            for (int j = 0; j < paths.size(); j ++) {
                if (paths[j].s || paths[j].f == 0)
                    result += unsat[-paths[j].f];
                if (paths[j].s && paths[j].f == 0)
                    result ++;
                
                result += sat[-paths[j].f];
            }
            
            for (int j = 0; j < paths.size(); j ++) {
                if (paths[j].s)
                    sat[paths[j].f] ++;
                else
                    unsat[paths[j].f] ++;
            }
        }       
    }
    
    return (result);
}

long long centroid(int ind) {
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
            if (par[cur] != con[cur][i].f && !blocked[con[cur][i].f]) {
                sz = max(sz, summ[con[cur][i].f]);
                q.push(con[cur][i].f);        
            }
        }
        
        if (sz < big) {
            big = sz;
            centr = cur;
        }
    }
    
    long long ways = 0ll;
    
    //We found centroid, and we're going to call solve() method here
    //For different problems, this solve() method can change
    ways = solve(centr);
    blocked[centr] = true;
    
    for (int i = 0; i < con[centr].size(); i ++)
        if (!blocked[con[centr][i].f])
            ways += centroid(con[centr][i].f);
    
    return (ways);
}

int main() {
    cin >> N >> L >> W; 
    
    int p, w;
    for (int i = 0; i < N; i ++) {
        cin >> p >> w;
        con[p - 1].push_back(ii(i + 1, w));
        con[i + 1].push_back(ii(p - 1, w));
    }
    
    cout << centroid(0) << endl;
    return (0);
}