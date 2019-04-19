#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>

#define MAX_N 1200005
#define f first
#define s second

using namespace std;

int d[MAX_N], lca[MAX_N][23];
int Q;

int LCA (int a, int b) {
    int x = a;
    int y = b;
    
    if (d[x] > d[y]) {
        x = b;
        y = a;
    }
    
    for (int i = d[y] - d[x]; i > 0; i = (i & (i - 1))) { 
        y = lca[y][(int)(log2(i - (i & (i - 1)))) + 1];
    }
    
    if (x == y)
        return (x);
    
    for (int i = 22; i >= 0; i --) {
        if (lca[x][i] != lca[y][i]) {
            x = lca[x][i];
            y = lca[y][i];
        }
    }
    
    return (lca[x][1]);
}

int dist(int a, int b) {
    return (d[a] + d[b] - 2 * d[LCA(a, b)]);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    cin >> Q;
    
    d[0] = 1; d[1] = 2; d[2] = 2; d[3] = 2;
    
    lca[1][0] = 1; 
    lca[2][0] = 2;
    lca[3][0] = 3;
    
    int N = 4, a;
    int n1 = 1, n2 = 2, diam = 2;
    
    for (int i = 0; i < Q; i ++) {
        cin >> a; a --;
        lca[N][1] = a; lca[N][0] = N;
        lca[N + 1][1] = a; lca[N + 1][0] = N + 1;
        
        d[N] = d[a] + 1;
        d[N + 1] = d[a] + 1;
        
        for (int j = 2; j < 23; j ++)
            lca[N][j] = lca[lca[N][j - 1]][j - 1];
        
        for (int j = 2; j < 23; j ++)
            lca[N + 1][j] = lca[lca[N + 1][j - 1]][j - 1];
        
        if (diam < dist(N, N + 1)) {
            diam = dist(N, N + 1);
            n1 = N;
            n2 = N + 1;
        }
        
        if (diam < dist(n1, N)) {
            diam = dist(n1, N);
            n1 = n1;
            n2 = N;
        }
        
        if (diam < dist(n2, N)) {
            diam = dist(n2, N);
            n1 = N;
            n2 = n2;
        }
        
        cout << diam << endl;
        N += 2;
    }
    
    return (0);
}