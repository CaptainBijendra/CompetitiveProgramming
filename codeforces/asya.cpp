#include <iostream>
#include <vector>

#define MAX_N 150005
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];

long long ar[MAX_N], par[MAX_N], sz[MAX_N];
long long N, M;

void init(long long size) {
    for (long long i = 0; i < size; i ++) {
        par[i] = i;
        sz[i] = 1;
        con[i].push_back(i);
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
    cin >> N;
    init(MAX_N);
    
    int a, b, x, y;
    for (int i = 0; i < N - 1; i ++) {
        cin >> a >> b;
        a --; b --;
        
        if (sz[find(a)] > sz[find(b)]) {
            x = find(b);
            y = find(a);
        }
        
        else {
            x = find(a);
            y = find(b);
        }
        
        for (int i = 0; i < con[x].size(); i ++)
            con[y].push_back(con[x][i]);
                
        con[x].clear();
        merge(a, b);
    }
    
    x = find(0);
    for (int i = 0; i < con[x].size(); i ++)
        cout << (con[x][i] + 1) << " ";
    
    cout << endl;
    return (0);
}