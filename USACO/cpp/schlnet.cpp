#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#include <math.h>

#define MAX_N 105
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];
vector<int> connected[MAX_N];

bool vis[MAX_N], rooter[MAX_N];

int ind[MAX_N], root[MAX_N], component[MAX_N];

int col[MAX_N], in[MAX_N];
int N, co, scc;

vector< vector<int> > SCC;
vector<int> stack;

void DFS (int ind, int color) {
    col[ind] = color;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        if (!col[con[ind][i]]) {
            DFS (con[ind][i], color);
        }
    }
}

void recurse(int v) {
    ind[v] = co;
    root[v] = co; co ++;

    vis[v] = true;
    stack.push_back(v);

    for (int i = 0; i < con[v].size(); i ++) {
        if (ind[con[v][i]] == -1) {
            recurse(con[v][i]);
            root[v] = min(root[v], root[con[v][i]]);
        }

        else if (vis[con[v][i]]) {
            root[v] = min(root[v], root[con[v][i]]);
        }
    }

    if (root[v] == ind[v]) {
        SCC.push_back(vector<int>());

        int a = -1;

        while (a != v) {
            a = stack.back();
            stack.pop_back();

            vis[a] = false;
            SCC[scc].push_back(a);
            
            component[a] = scc;
        }

        scc ++;
    }
}

int main() {
    cin >> N;
    
    int x;
    for (int i = 0; i < N; i ++) {
        while (true) {
            cin >> x;
            
            if (x == 0)
                break;
            else {
                con[i].push_back(x - 1);
                in[x - 1] ++;
            }
        }
    }
    
    int color = 1;
    int answer = 0;
    
    for (int i = 0; i < N; i ++) {
        if (!col[i] && !in[i]) {
            DFS (i, color);
            color ++;
        }
    } 
    
    for (int i = 0; i < N; i ++) {
        if (!col[i]) {
            DFS(i, color);
            color ++;
        }
        
        ind[i] = -1;
    }
    
    color --;
    co = 0;
    scc = 0;
    
    for (int i = 0; i < N; i ++)
        if (ind[i] == -1)
            recurse(i);
    
    for (int i = 0; i < SCC.size(); i ++) {
        for (int j = 0; j < SCC[i].size(); j ++) {
            for (int k = 0; k < con[SCC[i][j]].size(); k ++) {
                if (component[SCC[i][j]] != component[con[SCC[i][j]][k]]) {
                    connected[component[SCC[i][j]]].push_back(component[con[SCC[i][j]][k]]);
                    rooter[component[con[SCC[i][j]][k]]] = true;
                }
            }        
        }
    }
    
    int leaves = 0;
    int rooters = 0;
    
    for (int i = 0; i < SCC.size(); i ++) {
        leaves += (connected[i].size() == 0);
        rooters += (!rooter[i]);
    
        if (connected[i].size() == 0 && !rooter[i])
            rooters --;
    }
    
    if (rooters == 0)
        rooters = 1;
    
    answer = rooters + leaves - 1;
    
    if (SCC.size() == 1)
        answer --;
        
    if (leaves == (rooters + 1))
        answer = leaves;

    cout << color << endl;
    cout << answer << endl;
    return (0);
}
   