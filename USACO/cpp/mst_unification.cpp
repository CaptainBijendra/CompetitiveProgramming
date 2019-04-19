#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<long long, long long> ii;
typedef pair<long long, ii> pii;

vector<pii> edge;

long long par[MAX_N], sz[MAX_N], ans[MAX_N];
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
    init(MAX_N);
    
    long long a, b, c;
    for (long long i = 0; i < M; i ++) {
        cin >> a >> b >> c;
        edge.push_back(pii(c, ii(a - 1, b - 1)));
    }
    
    sort(edge.begin(), edge.end());
    
    long long ans = 0;
    
    for (long long i = 0; i < edge.size(); ) {
        long long cur = edge[i].f;
        long long prev = i;
        long long possible = 0;
        
        while (edge[i].f == cur) {
            if (find(edge[i].s.f) != find(edge[i].s.s))
                possible ++;
            
            i ++;
        }
        
        i = prev;
        
        while (edge[i].f == cur) {
            if (find(edge[i].s.f) != find(edge[i].s.s)) {
                merge(find(edge[i].s.f), find(edge[i].s.s));
                possible --;
            }
            
            i ++;
        }
        
        ans += possible;
    }

    cout << ans << endl;
    return (0);
}