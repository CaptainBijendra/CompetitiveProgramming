#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>

#define MAX_N 600000
#define MAX_Y 755
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

bool active[MAX_N];

int ar[MAX_Y][MAX_Y];
int par[MAX_N], sz[MAX_N], step[MAX_N];

int N;

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
    ifstream fin ("valleys.in");
    ofstream fout ("valleys.out");
    
    fin >> N;

    init(MAX_N);
    vector<ii> loc;
    
    for (int i = 0; i < N; i ++)
        for (int j = 0; j < N; j ++) {
            fin >> ar[i][j];
            loc.push_back(ii(ar[i][j], i * N + j));
        }
    
    sort(loc.begin(), loc.end());
    
    for (int i = 0; i < loc.size(); i ++) {
        active[loc[i].s] = true;
    
        if (((loc[i].s + 1) % N != 0) && active[loc[i].s + 1])
            merge(loc[i].s, loc[i].s + 1);
        if ((loc[i].s % N != 0) && active[loc[i].s - 1])
            merge(loc[i].s, loc[i].s - 1);
        if (loc[i].s + N < N * N && active[loc[i].s + N])
            merge(loc[i].s, loc[i].s + N);
        if (loc[i].s - N >= 0 && active[loc[i].s - N])
            merge(loc[i].s, loc[i].s - N);
        
        step[i] = sz[find(loc[i].s)];
    }
    
    reverse(loc.begin(), loc.end());
    init(MAX_N);
    
    int comps = 1;
    long long ans = N * N;

    for (int i = 0; i < N * N; i ++)
        active[i] = false;
    
    for (int i = 0; i < loc.size() - 1; i ++) {
        active[loc[i].s] = true;
        comps ++;
        
        if ((loc[i].s + 1) % N == 0) {
            if (find(loc[i].s) != find(N * N)) {
                merge(loc[i].s, N * N);
                comps --;
            }
        }
        
        else if (active[loc[i].s + 1]) {
            if (find(loc[i].s + 1) != find(loc[i].s)) {
                merge(loc[i].s, loc[i].s + 1);
                comps --;
            }    
        }
        
        if (loc[i].s % N == 0) {
            if (find(loc[i].s) != find(N * N)) {
                merge(loc[i].s, N * N);
                comps --;
            }
        }

        else if (active[loc[i].s - 1]) {
            if (find(loc[i].s - 1) != find(loc[i].s)) {
                merge(loc[i].s, loc[i].s - 1);
                comps --;
            }    
        }
        
        if (loc[i].s + N >= N * N) {
            if (find(loc[i].s) != find(N * N)) {
                merge(loc[i].s, N * N);
                comps --;
            }
        }
        
        else if (active[loc[i].s + N]) {
            if (find(loc[i].s + N) != find(loc[i].s)) {
                merge(loc[i].s, loc[i].s + N);
                comps --;
            }        
        }
        
        if (loc[i].s - N < 0) {
            if (find(loc[i].s) != find(N * N)) {
                merge(loc[i].s, N * N);
                comps --;
            }
        } 
        
        else if (active[loc[i].s - N]) {
            if (find(loc[i].s - N) != find(loc[i].s)) {
                merge(loc[i].s, loc[i].s - N);
                comps --;
            }                
        }
        
        if ((loc[i].s + 1) % N != 0 && loc[i].s + N < N * N) {
            if (find(loc[i].s + N + 1) != find(loc[i].s) && active[loc[i].s + N + 1]) {
                merge(loc[i].s, loc[i].s + N + 1);
                comps --;
            }
        }
        
        if ((loc[i].s + 1) % N != 0 && loc[i].s - N >= 0) {
            if (find(loc[i].s + 1 - N) != find(loc[i].s) && active[loc[i].s - N + 1]) {
                merge(loc[i].s + 1 - N, loc[i].s);
                comps --;
            }
        }
        
        if (loc[i].s % N != 0 && loc[i].s + N < N * N) {
            if (find(loc[i].s + N - 1) != find(loc[i].s) && active[loc[i].s + N - 1]) {
                merge(loc[i].s + N - 1, loc[i].s);
                comps --;
            }
        }
        
        if (loc[i].s % N != 0 && loc[i].s - N >= 0) {
            if (find(loc[i].s - N - 1) != find(loc[i].s) && active[loc[i].s - N - 1]) {
                merge(loc[i].s - N - 1, loc[i].s);
                comps --;
            }
        }
        
        if (comps <= 1)
            ans += step[loc.size() - 2 - i];      
    }
    
    fout << ans << endl;
    return (0);
}