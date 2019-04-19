#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
#include <queue>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

typedef pair<long long, long long> ii;
typedef pair<long long, ii> pii;

vector<pii> edges;

long long ar[MAX_N], par[MAX_N], sz[MAX_N];
long long N, M;

void init(long long size) {
    for (long long i = 0; i < size; i ++) {
        par[i] = i;
        sz[i] = 1;
    }
}

long long find(long long x) {
    while (x != par[x]) {
        par[x] = par[par[x]];
        x = par[x];
    }

    return (x);
}

void merge(long long x, long long y) {
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
    cin >> N >> M;
    
    long long small = 1000000000000009;
    long long ind = -1;
    
    for (long long i = 0; i < N; i ++) {
        cin >> ar[i];
        
        if (ar[i] < small) {
            small = ar[i];
            ind = i;
        }
    }
    
    long long a, b, c;
    for (long long i = 0; i < M; i ++) {
        cin >> a >> b >> c;
        a --; b --;
        
        edges.push_back(pii(min(c, ar[a] + ar[b]), ii(a, b)));
    }
    
    init(MAX_N);
    
    for (int i = 0; i < N; i ++) {
        if (i == ind)
            continue;
        
        edges.push_back(pii(ar[i] + ar[ind], ii(i, ind)));
    }
    
    sort(edges.begin(), edges.end());

    long long ans = 0ll;
    
    for (long long i = 0; i < edges.size(); i ++) {
        long long u = edges[i].s.f;
        long long v = edges[i].s.s;
        long long cst = edges[i].f;
        
        if (find(u) != find(v)) {
            merge(u, v);
            ans += cst;
        }
    }
    
    cout << ans << endl;
    return (0);
}