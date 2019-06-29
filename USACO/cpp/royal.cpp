#include <algorithm>
#include <vector>
#include <iostream>

#define MAX_N 200005
#define f first
#define s second 

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> pii;

bool used[MAX_N];

int par[MAX_N], sz[MAX_N];
int N, M;

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

bool cmp(pii a, pii b) {
	return (a.s > b.s);
}

int main() {
	cin >> N >> M;
	init(MAX_N);
	
	vector<pii> vc;
	
	int a, b, c;
	for (int i = 0; i < M; i ++) {
		cin >> a >> b >> c;
		vc.push_back(pii(ii(a, b), c));
	}
	
	sort(vc.begin(), vc.end(), cmp);
	
	long long sum = 0ll;
	bool bef;
	
	for (int i = 0; i < vc.size(); i ++) {
		if (find(vc[i].f.f) == find(vc[i].f.s) && (!used[find(vc[i].f.f)])) {
			sum += vc[i].s;
			used[find(vc[i].f.f)] = true;
		}
		
		if (find(vc[i].f.f) != find(vc[i].f.s) && (!used[find(vc[i].f.f)] || !used[find(vc[i].f.s)])) {
			sum += vc[i].s;
			bef = (used[find(vc[i].f.f)] || used[find(vc[i].f.s)]);
			merge(vc[i].f.f, vc[i].f.s);
			used[find(vc[i].f.f)] = (used[find(vc[i].f.f)] || bef);
		}
	}
	
	cout << sum << endl; 
	return (0);
}