#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

vector<int> con[MAX_N];
vector<ii> query[350];

bool active[MAX_N], vis[MAX_N], beg[MAX_N];

int par[MAX_N][23], d[MAX_N], cost[MAX_N], DP[MAX_N], DP2[MAX_N];
int N, M;

void DFS (int ind, int prev) {
    par[ind][0] = ind;
    par[ind][1] = prev;
    
    d[ind] = d[prev] + 1;
    
    for (int i = 2; i < 23; i ++) 
        par[ind][i] = par[par[ind][i - 1]][i - 1]; 
    
    for (int i = 0; i < con[ind].size(); i ++) 
        if (con[ind][i] != prev) 
            DFS(con[ind][i], ind);
}

int LCA (int a, int b) {
    int x = a;
    int y = b;
    
    if (d[x] > d[y]) {
        x = b;
        y = a;
    }
    
    for (int i = d[y] - d[x]; i > 0; i = (i & (i - 1))) { 
        y = par[y][(int)(log2(i - (i & (i - 1)))) + 1];
    }
    
    if (x == y)
        return (x);
    
    for (int i = 22; i >= 0; i --) {
        if (par[x][i] != par[y][i]) {
            x = par[x][i];
            y = par[y][i];
        }
    }
    
    return (par[x][1]);
}

int dist(int a, int b) {
    if (d[a] + d[b] - 2 * d[LCA(a, b)] < 0)
        return 0;
    
    return (d[a] + d[b] - 2 * d[LCA(a, b)]);
}

void calc(int ind) {
    vis[ind] = true;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        if (!vis[con[ind][i]] && active[con[ind][i]]) {
            calc(con[ind][i]);
            DP[ind] = max(DP[ind], DP[con[ind][i]] + 1);
        }
    }
}

void DFS2(int ind, int above) {
    vis[ind] = true;
    cost[ind] = max(cost[ind], max(DP[ind], above));
    
    int big1 = -1;
    int big2 = -1;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        if (!vis[con[ind][i]] && active[con[ind][i]]) {
            if (big1 == -1)
                big1 = con[ind][i];
            else {
                if (DP[con[ind][i]] > DP[big1]) {
                    big2 = big1;
                    big1 = con[ind][i];
                }
                
                else {
                    if (big2 == -1)
                        big2 = con[ind][i];
                    else {
                        if (DP[con[ind][i]] > DP[big2])
                            big2 = con[ind][i];
                    }
                }        
            }
        }
    }
    
    for (int i = 0; i < con[ind].size(); i ++) {
        if (!vis[con[ind][i]] && active[con[ind][i]]) {
            if (con[ind][i] == big1)
                DFS2(con[ind][i], max(above + 1, (big2 == -1 ? -2 : DP[big2]) + 2));
            else
                DFS2(con[ind][i], max(above + 1, DP[big1] + 2));
        }
    }
}

int main() {
    ifstream fin ("newbarn.in");
    ofstream fout ("newbarn.out");
    
    fin >> M;
    
    int a, b, cnt = 0;
    char c;
    
    int block = sqrt(M);
    
    for (int i = 0; i < M; i ++) {
        fin >> c;
        fin >> a;
        
        if (c == 'B') {
            if (a != -1) {
                con[a - 1].push_back(cnt);
                con[cnt].push_back(a - 1);
            }
            
            query[i / block].push_back(ii(cnt, 0));
            cnt ++;
        }
        
        else {
            query[i / block].push_back(ii(a - 1, 1));
        }
    }
    
    N = cnt;
    DFS (0, 0);
    
    for (int i = 1; i < N; i ++)
        if (!d[i]) 
            DFS (i, i);
    
    int cur = 0;
    
    for (int i = 0; i < ((M + block - 1) / block); i ++) { //sqrt(N)
        if (i > 0) {
            for (int j = 0; j < query[i - 1].size(); j ++) //sqrt(N)
                if (query[i - 1][j].s == 0)
                    active[query[i - 1][j].f] = true;

            for (int j = 0; j <= cur; j ++)
                vis[j] = false;
            
            for (int j = 0; j <= cur; j ++)
                if (!vis[j] && active[j])
                    calc(j);
            
            for (int j = 0; j <= cur; j ++)
                vis[j] = false;
            
            for (int j = 0; j <= cur; j ++)
                if (!vis[j] && active[j])
                    DFS2(j, 0);
        }
    
        for (int j = 0; j < query[i].size(); j ++) { //sqrt(N)
            if (query[i][j].s == 0) {
                cur ++;
                continue;
            }
            
            int big = 0;
            
            for (int k = 0; k < j; k ++) { //sqrt(N)
                if (query[i][k].s == 1 || par[query[i][k].f][22] != par[query[i][j].f][22])
                    continue;
                
                big = max(big, dist(query[i][k].f, query[i][j].f));
            }
            
            //CHECK DISTANCE OF NEW BARN WITH NEW BARNS BEFORE IT (DONE FOR SURE)
            //CHECK DISTANCE OF OLD BARN WITH NEW BARNS BEFORE IT (DONE FOR SURE)
            //CHECK DISTANCE OF NEW BARNS WITH OLD BARNS BEFORE IT (IF THE ONE BELOW WORKS, THEN THIS SHOULD ALSO WORK)
            //CHECK DISTANCE OF OLD BARNS WITH OLD BARNS BEFORE IT (MIGHT HAVE TO CHECK THIS)
            
            if (!active[query[i][j].f]) {
                int v = query[i][j].f;
                
                for (int k = 22; k >= 0; k --) {
                    if (!active[par[v][k]])
                        v = par[v][k];
                }
                
                v = par[v][1];
                cost[query[i][j].f] = max(cost[query[i][j].f], d[query[i][j].f] - d[v] + cost[v]);
            }
        
            fout << max(cost[query[i][j].f], big) << endl;
        }
    }

    return (0);
}
