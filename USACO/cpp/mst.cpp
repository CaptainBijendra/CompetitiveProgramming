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
    
    int a, b, c;
    for (int i = 0; i < M; i ++) {
        cin >> a >> b >> c;
        edges.push_back(pii(c, ii(a - 1, b - 1)));
    }
    
    init(MAX_N);
    sort(edges.begin(), edges.end());
    
    long long sum = 0ll;
    int sz = N;
    
    for (int i = 0; i < edges.size(); i ++) {
        if (sz == 2)
            break;
        
        int c = edges[i].s.f;
        int v = edges[i].s.s;
        
        if (find(c) != find(v)) {
            merge(c, v);
            
            sz --;
            sum += edges[i].f;
        }
    }
    
    cout << sum << endl;
    return (0);
}