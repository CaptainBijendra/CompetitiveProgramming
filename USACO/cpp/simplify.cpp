#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string.h>
#include <math.h>

#define MOD 1000000007
#define MAX_N 100005
#define MAX_M 100005
#define f first
#define s second

using namespace std;

typedef pair<long long, long long> ii;
priority_queue < pair<long long, ii> > EdgeList;

map<ii, int> mp;

long long sz[MAX_M], par[MAX_M];
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

    for (long long i = 0; i < M; i ++) {
        long long a, b, c;

        cin >> a >> b >> c;
        EdgeList.push(make_pair(-1 * c, ii(a - 1, b - 1)));
    }

    long long cst = 0;
    long long mult = 1;

    while (!EdgeList.empty()) {
        pair<long long, ii> cur = EdgeList.top();
        priority_queue < pair<long long, ii> > EdgeList2, EdgeList3;

        map<int, int> vis;
        map<int, bool> vis2;
        map<ii, bool> num_same;

        long long cnt_extra = 0;
        long long tot_cnt = 0;

        long long components = 0;
        long long big = 0, big2 = 0, sze = 0;
        
        while (EdgeList.top().f == cur.f && !EdgeList.empty()) {
            pair<long long, ii> nxt = EdgeList.top();
            EdgeList.pop(); 

            long long x = find(nxt.s.f);
            long long y = find(nxt.s.s);
            
            if (x == y)
                continue;

            sze ++;

            EdgeList2.push(nxt);
            if (!vis[x]) {
                components ++;
            }

            vis[x] ++;
            
            if (!vis[y]) {
                components ++;
            }
            
            vis[y] ++;
            
            if (!num_same[ii(min(x, y), max(x, y))])
                big2 ++;
            
            num_same[ii(min(x, y), max(x, y))] = true;
        }
        
        long long a = 1;
        
        while (!EdgeList2.empty()) {
            pair<long long, ii> nxt = EdgeList2.top();
            EdgeList2.pop();

            long long x = find(nxt.s.f);
            long long y = find(nxt.s.s);
            
            if (x == y)
                continue;
            
            EdgeList3.push(nxt);
            if (!vis2[x]) {
                vis2[x] = true;
                a *= vis[x];
            }
            
            if (!vis2[y]) {
                vis2[y] = true;
                a *= vis[y];
            }            
        }
        
         while (!EdgeList3.empty()) {
            pair<long long, ii> nxt = EdgeList3.top();
            EdgeList3.pop();
            
            long long x = find(nxt.s.f);
            long long y = find(nxt.s.s);             
            
            if (x != y) {
                merge(x, y);
                cst += -1 * cur.f;
            }
        }
        
        if (sze == 3) {
            if (components == 2 && big2 == 1)
                mult = (mult * 3) % MOD;
            else if (components == 3) {
                if (big2 == 3)
                    mult = (mult * 3) % MOD;
                else if (big2 == 2)
                    mult = (mult * 2) % MOD;
            }
        
            else if (components == 4) {
                if (big2 == 2)
                    mult = (mult * 2) % MOD;
            }
        }    
    
        if (sze == 2) {
            if (components == 2 && big2 == 1)
                mult = (mult * 2) % MOD;
        }
    }

    cout << cst << " " << mult << endl;
    return (0);
}