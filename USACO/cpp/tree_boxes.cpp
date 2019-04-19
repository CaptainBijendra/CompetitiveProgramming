#include <iostream>
#include <vector>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
ii cow[MAX_N];

vector<int> con[MAX_N];

bool vis[MAX_N];

int d[MAX_N], lca[MAX_N][23];
int N;
int X = 1;
int Y = 1;

void addRoad(int a, int b) {
    N = getN();

    con[a].push_back(b);
    con[b].push_back(a);
}

void DFS1 (int ind, int prev) {
    vis[ind] = true;
    d[ind] = d[prev] + 1;

    lca[ind][0] = ind;
    lca[ind][1] = prev;

    for (int i = 2; i < 23; i ++)
        lca[ind][i] = lca[lca[ind][i - 1]][i - 1];

    for (int i = 0; i < con[ind].size(); i ++)
        if (!vis[con[ind][i]])
            DFS1 (con[ind][i], ind);

    vis[ind] = false;
}

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

int LCA2 (int a, int b) {
    int x = a;
    int y = b;

    if (d[x] > d[y]) {
        x = b;
        y = a;
    }

    for (int i = d[y] - d[x] - 1; i > 0; i = (i & (i - 1))) {
        y = lca[y][(int)(log2(i - (i & (i - 1)))) + 1];
    }
    
    return (y);
}

void find_x(int ind) {
    cow[ind].f = X;
    X ++;
    vis[ind] = true;

    for (int i = 0; i < con[ind].size(); i ++)
        if (!vis[con[ind][i]])
            find_x(con[ind][i]);

    vis[ind] = false;
}

void find_y(int ind) {
    cow[ind].s = Y;
    Y ++;
    vis[ind] = true;

    for (int i = con[ind].size() - 1; i >= 0; i --)
        if (!vis[con[ind][i]])
            find_y(con[ind][i]);

    vis[ind] = false;
}

void buildFarms() {
    DFS1(0, 0);

    find_x(0);
    find_y(0);

    for (int i = 0; i < N; i ++)
        setFarmLocation(i, cow[i].f, cow[i].s);
}

void notifyFJ(int a, int b) {
    int x = LCA(a, b);

    if (x == a || x == b)
        addBox(cow[x].f, cow[x].s, max(cow[a].f, cow[b].f), max(cow[a].s, cow[b].s));
    else {
        addBox(cow[x].f, cow[x].s, cow[a].f, cow[a].s);
        x = LCA2(x, b);
        addBox(cow[x].f, cow[x].s, cow[b].f, cow[b].s);
    }
}