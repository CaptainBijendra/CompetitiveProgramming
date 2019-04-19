#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <string.h>
#include <math.h>

#define INF 2000000009
#define MAX_N 20005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> pii;

vector<pii> con[MAX_N];

map<int, bool> vis[MAX_N];
map<int, int> dist[MAX_N];

int N, M;

int main() {
    cin >> N >> M;
    
    int a, b, c, d;
    for (int i = 0; i < M; i ++) {
        cin >> a >> b >> c >> d;
        con[a - 1].push_back(pii(ii(b - 1, c), d));
        con[b - 1].push_back(pii(ii(a - 1, c), d));
    }
    
    priority_queue<pii> pq;
    pq.push(pii(ii(0, 0), -1));
    dist[0][-1] = 0;
        
    int in;
    int ans = INF;
    
    while (!pq.empty()) {
        pii top = pq.top(); pq.pop();
        d = top.f.f; in = top.f.s;
        c = top.s;
        
        if (in == N - 1)
            ans = min(ans, d);
            
            for (int j = 0; j < con[in].size(); j ++) {
                if (d + con[in][j].f.s < dist[con[in][j].f.f][con[in][j].s] || !vis[con[in][j].f.f][con[in][j].s]) {
                    if (c != con[in][j].s) {
                        dist[con[in][j].f.f][con[in][j].s] = d + con[in][j].f.s;
                        pq.push(pii(ii(dist[con[in][j].f.f][con[in][j].s], con[in][j].f.f), con[in][j].s));
                    
                        vis[con[in][j].f.f][con[in][j].s] = true;
                    }        
                }
            }
    }
    
    cout << (ans) << endl;
    return (0);
}