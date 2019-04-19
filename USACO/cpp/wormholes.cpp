#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>

#define INF 2000000009
#define MAX_N 505
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> pii;

int T, N, M, W;

int main() {
    cin >> T;
    
    for (int jj = 0; jj < T; jj ++) {
        cin >> N >> M >> W;
        
        vector<pii> edges;
        int d[MAX_N];

        int a, b, c;
        for (int i = 0; i < M; i ++) {
            cin >> a >> b >> c;
            
            edges.push_back(pii(ii(a - 1, b - 1), c));
            edges.push_back(pii(ii(b - 1, a - 1), c));
        }
        
        for (int i = 0; i < W; i ++) {
            cin >> a >> b >> c;
            edges.push_back(pii(ii(a - 1, b - 1), -c));
        }
        
        for (int i = 0; i < N; i ++) {
            edges.push_back(pii(ii(N, i), 0));
            d[i] = INF;
        }
    
        d[N] = 0;
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < edges.size(); j ++) {
                int cur = edges[j].f.f;
                int end = edges[j].f.s;
                
                if (d[end] > d[cur] + edges[j].s) {
                    d[end] = d[cur] + edges[j].s;
                }
            }
        }
        
        bool flag = false;
        
        for (int i = 0; i < edges.size(); i ++)
            if (d[edges[i].f.s] > d[edges[i].f.f] + edges[i].s) {
                flag = true;
                break;
            }
        
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return (0);
}