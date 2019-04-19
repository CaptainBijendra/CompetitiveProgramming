#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <algorithm>

#define MAX_N 100005
#define MOD 1000000007

using namespace std;

vector< vector<int> > SCC;

vector<int> con[MAX_N];
vector<int> stack;

bool in[MAX_N];

int ind[MAX_N], root[MAX_N], edges[MAX_N];
int N, M, co, scc;

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
        SCC.push_back(vector<int>());

        int a = -1;

        while (a != v) {
            a = stack.back();
            stack.pop_back();

            in[a] = false;
            SCC[scc].push_back(a);
        }

        scc ++;
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i ++) {
        int a, b;

        cin >> a;
        a --;
        
        con[i].push_back(a);
        con[a].push_back(i);
    }

    co = 0;
    scc = 0;

    for (int i = 0; i < N; i ++) { ind[i] = -1; }
    for (int i = 0; i < N; i ++) {
        if (ind[i] == -1) { recurse(i); }
    }

    cout << scc + 1 << endl;
    return (0);
}