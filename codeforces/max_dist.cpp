#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> pii;

vector<pii> edge;

int par[MAX_N], sz[MAX_N], fnd[MAX_N];
int N, M, K, sweep;

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

bool con() {
    while (sweep < K && find(fnd[sweep - 1]) == find(fnd[sweep]))
        sweep ++;
        
    return (sweep == K);
}

int main() {
    cin >> N >> M >> K;
    init(MAX_N);
    
    int a;
    for (int i = 0; i < K; i ++) {
        cin >> fnd[i];
        fnd[i] --;
    }
    
    int b, c;
    for (int i = 0; i < M; i ++) {
        cin >> a >> b >> c;
        edge.push_back(pii(c, ii(a - 1, b - 1)));
    }
    
    sort(edge.begin(), edge.end());
    sweep = 1;
    
    int lft = 1;
    int cur = edge[0].f;
    
    merge(edge[0].s.f, edge[0].s.s);
    
    while (true) {
        while (lft < edge.size() && edge[lft].f == cur) {
            merge(edge[lft].s.f, edge[lft].s.s);
            lft ++;
        }

        if (con()) {
            for (int i = 0; i < K; i ++)
                cout << cur << " ";
            
            cout << endl;
            return (0);
        }
        
        cur = edge[lft].f;
    }

    return (0);
}