#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>

#define MAX_N 100005
#define MOD 1000000007

using namespace std;

vector<int> con[MAX_N], con2[MAX_N];
vector<int> stack, stck;

bool in[MAX_N], vis[MAX_N], vis2[MAX_N], vis3[MAX_N], vis4[MAX_N];

int ind[MAX_N], root[MAX_N], col[MAX_N], cst[MAX_N], cster[MAX_N], DP[MAX_N];
int T, N, co, scc;

//Tarjan's
void recurse(int v) {
    ind[v] = co;
    root[v] = co; co ++;

    in[v] = true;
    stack.push_back(v);

    for (int i = 0; i < con[v].size(); i ++) {
        if (ind[con[v][i]] == -1) {
            recurse(con[v][i]);
            root[v] = min(root[v], root[con[v][i]]);
        }

        else if (in[con[v][i]]) {
            root[v] = min(root[v], root[con[v][i]]);
        }
    }

    if (root[v] == ind[v]) {
        int a = -1;

        while (a != v) {
            a = stack.back();
            stack.pop_back();

            in[a] = false;
            col[a] = scc;
        }

        scc ++;
    }
}

void DFS (int ind) {
    vis[ind] = true;
    
    for (int i = 0; i < con2[ind].size(); i ++)
        if (!vis[con2[ind][i]])
            DFS (con2[ind][i]);
}

void topo(int ind) {
    vis3[ind] = true;
    
    for (int i = 0; i < con2[ind].size(); i ++)
        if (!vis3[con2[ind][i]])
            topo(con2[ind][i]);
    
    stck.push_back(ind);
}

int main() {
    cin >> T;
    
    for (int ii = 0; ii < T; ii ++) {
        cin >> N;
        
        int a, b;
        
        co = 0;
        scc = 0;
        stack.clear();
        stck.clear();

        for (int i = 0; i < N; i ++)
            con2[i].clear();

        for (int i = 0; i < N; i ++) {
            cin >> a >> b;
            con[i].clear();

            col[i] = -1;
            
            con[i].push_back(a - 1);
            con[i].push_back(b - 1);
            
            con2[a - 1].push_back(i);
            con2[b - 1].push_back(i);
            
            vis[i] = false;
            vis2[i] = false;
            vis3[i] = false;
            vis4[i] = false;
            
            cster[i] = 0;
            in[i] = false;
            DP[i] = 0;
            root[i] = MAX_N;
        }
        
        for (int i = 0; i < N; i ++)
            cin >> cst[i];
        
        DP[0] = 1;
        DFS(0);
        topo(0);
            
        vector<int> ord;
        for (int i = stck.size() - 1; i >= 0; i --)
            ord.push_back(stck[i]);
        
        for (int i = 0; i < ord.size(); i ++) {
            vis4[ord[i]] = true;
            for (int j = 0; j < con2[ord[i]].size(); j ++) {
                if (!vis4[con2[ord[i]][j]]) {
                    DP[con2[ord[i]][j]] += DP[ord[i]];
                    DP[con2[ord[i]][j]] %= MOD;
                }        
            }   
        }
        
        for (int i = 0; i < N; i ++) { ind[i] = -1; }
        for (int i = 0; i < N; i ++) {
            if (ind[i] == -1) { recurse(i); }
        }
        
        for (int i = 0; i < N; i ++)
            cster[col[i]] = max(cster[col[i]], cst[i]);
        
        long long sum = 0ll;
        
        bool flag = false;
        for (int i = 0; i < N; i ++) {
            if (((col[con[i][0]] == col[i] && vis[con[i][1]]) || (col[con[i][1]] == col[i] && vis[con[i][0]])) && cster[col[i]] > 0) {
                flag = true;
                break;
            }
        
            if (vis[i])
                sum = (sum + DP[i] * cst[i]) % MOD;
        }
        
        if (flag) {
            cout << "Case #" << (ii + 1) << ": UNBOUNDED" << endl;
        } else {
            cout << "Case #" << (ii + 1) << ": " << sum << endl;
        }
    }
}