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

typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef pair<ii, int> iip;

vector<pii> edge;
vector<iip> query;

int par[MAX_N], sz[MAX_N], ans[MAX_N];
int N, Q;

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

bool cmp(iip a, iip b) {
    return (a.f.f < b.f.f);
}

int main() {
    ifstream fin ("mootube.in");
    ofstream fout ("mootube.out");
    
    fin >> N >> Q;
    
    init(MAX_N);
    
    int a, b, c;
    for (int i = 0; i < N - 1; i ++) {
        fin >> a >> b >> c;
        edge.push_back(pii(c, ii(a - 1, b - 1)));
    }
    
    sort(edge.begin(), edge.end());
    reverse(edge.begin(), edge.end());
    
    for (int i = 0; i < Q; i ++) {
        fin >> a >> b;
        query.push_back(iip(ii(a, b - 1), i));
    }
    
    sort(query.begin(), query.end(), cmp);
    reverse(query.begin(), query.end());
    
    int l2 = 0;
    
    for (int l1 = 0; l1 < Q; l1 ++) {
        while (l2 < (N - 1) && query[l1].f.f <= edge[l2].f) {
            int a = edge[l2].s.f;
            int b = edge[l2].s.s;
            
            if (find(a) != find(b))
                merge(a, b);
                
            l2 ++;
        }
        
        ans[query[l1].s] = sz[find(query[l1].f.s)] - 1;
    }

    for (int i = 0; i < Q; i ++)
        fout << ans[i] << endl;
    
    return (0);
}