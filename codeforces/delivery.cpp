#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

vector<ii> con[MAX_N];

int par[MAX_N], sz[MAX_N];
int N, M, C, Q;

void init(int size) {
    for (int i = 0; i < size; i ++) {
        par[i] = i;
        sz[i] = 1;
    }
}

int find(int x) {
    while (x != par[x]) {
        par[x] = par[par[x]];
        x = par[x];
    }

    return (x);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y)
        return;

    if (sz[x] > sz[y]) {
        par[y] = x;
        sz[x] += sz[y];
    }

    else {
        par[x] = y;
        sz[y] += sz[x];
    }
}

int main() {
    cin >> N >> M >> C >> Q;
    
    int a, b, c;
    for (int i = 0; i < M; i ++) {
        cin >> a >> b >> c;
        a --; b --;
        
        con[a].push_back(ii(c, b));
    }   
    
    init(MAX_N);
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < con[i].size(); j ++) {
            int cur = con[i][j].s;
            
            for (int k = 0; k < con[cur].size(); k ++) {
                if (con[cur][k].f == con[i][j].f) {
                    merge(cur, con[cur][k].s);
                }
            }
        }
    }
    
    char x;
    for (int i = 0; i < Q; i ++) {
        cin >> x;
        
        if (x == '?') {
            cin >> a >> b;
            a --; b --;
            
            bool pos = (find(a) == find(b));
            
            for (int j = 0; j < con[b].size(); j ++) {
                pos = (pos || (find(a) == find(con[b][j])));
            }
            
            cout << (pos ? "Yes" : "No") << endl;
        } else {
            cin >> a >> b >> c;
            a --; b --;
            
            con[a].push_back(ii(c, b));
        }
    }
    
    return (0);
}