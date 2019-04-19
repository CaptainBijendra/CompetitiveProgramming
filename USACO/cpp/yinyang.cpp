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

map<int, int> seen, sat, unsat;

bool blocked[MAX_N];

int summ[MAX_N], par[MAX_N];
int N;

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

void find_paths(int ind, int p, int sum) {
    paths.push_back(ii(sum, seen[sum] > 0));
    seen[sum] ++;

    for (int i = 0; i < con[ind].size(); i ++)
        if (!blocked[con[ind][i].f] && p != con[ind][i].f)
            find_paths(con[ind][i].f, ind, sum + con[ind][i].s);    
    
    seen[sum] --;
}

long long solve(int ind) {
    sat.clear();
    unsat.clear();
    
    long long result = 0ll;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        if (!blocked[con[ind][i].f]) {
            paths.clear();
            find_paths(con[ind][i].f, ind, con[ind][i].s);
            
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
    ifstream fin ("yinyang.in");
    ofstream fout ("yinyang.out");
    
    fin >> N;
    
    int a, b, c;
    for (int i = 0; i < N - 1; i ++) {
        fin >> a >> b >> c;
        con[a - 1].push_back(ii(b - 1, 2 * c - 1));
        con[b - 1].push_back(ii(a - 1, 2 * c - 1));
    }
    
    fout << centroid(0) << endl;
    return (0);
}