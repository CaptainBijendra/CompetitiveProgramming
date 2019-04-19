#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define INF 200000000
#define MAX_N 20005
#define MAX_K 205

using namespace std;

typedef pair<int, int> ii;

priority_queue<ii> pq;
vector<ii> con[MAX_N];

vector<int> hubs;

bool hub[MAX_N];

long long w[MAX_K][MAX_N], rw[MAX_N][MAX_K];
int N, M, K, Q;

int main() {
    cin >> N >> M >> K >> Q;
    
    int a, b, c, d, in;

    for (int i = 0; i < M; i ++) {
        cin >> a >> b >> c;
        con[a - 1].push_back(ii(b - 1, c));
    }

    for (int i = 0; i < K; i ++) {
        cin >> a; hub[a - 1] = true; 
        hubs.push_back(a - 1); 
    }            

    for (int i = 0; i < MAX_K; i ++) {
        for (int j = 0; j < MAX_N; j ++) { w[i][j] = INF; rw[j][i] = INF; }
    }
    
    for (int i = 0; i < K; i ++) {
        pq.push(ii(0, hubs[i]));
        w[hubs[i]][hubs[i]] = 0;

        while (!pq.empty()) {
            ii top = pq.top(); pq.pop();
            d = top.first; in = top.second;
            
            if (d == w[hubs[i]][in]) {
                for (int j = 0; j < con[in].size(); j ++) {
                    if (w[hubs[i]][in] + con[in][j].second < w[hubs[i]][con[in][j].first]) {
                        w[hubs[i]][con[in][j].first] = w[hubs[i]][in] + con[in][j].second;
                        pq.push(ii(w[hubs[i]][con[in][j].first], con[in][j].first));
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i ++) {
        pq.push(ii(0, i));
        rw[i][i] = 0;

        while (!pq.empty()) {
            ii top = pq.top(); pq.pop();
            d = top.first; in = top.second;
            
            if (d == rw[i][in]) {
                for (int j = 0; j < con[in].size(); j ++) {
                    if (hub[con[in][j].first]) {
                        if (rw[i][in] + con[in][j].second < rw[i][con[in][j].first]) {
                            rw[i][con[in][j].first] = rw[i][in] + con[in][j].second;
                            pq.push(ii(rw[i][con[in][j].first], con[in][j].first));
                        }
                    }        
                }
            }
        }
    }

    long long co = 0, tot = 0;
    long long ans;

    for (int i = 0; i < Q; i ++) {
        cin >> a >> b;
        ans = INF;

        for (int j = 0; j < hubs.size(); j ++) 
        { ans = min(ans, rw[a - 1][hubs[j]] + w[hubs[j]][b - 1]); }
        
        if (ans != INF) { co ++; tot += ans; }
    }
    
    cout << co << endl;
    cout << tot << endl;
    
    return (0);
}