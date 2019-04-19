#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 40005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

vector<ii> pastures;
vector<int> con[MAX_N];

bool vis[MAX_N];

int d[MAX_N], d2[MAX_N], cnt[MAX_N], DP[MAX_N], bad[MAX_N];
int N, M;

int main() {
    cin >> N >> M;
    
    int a, b;
    for (int i = 0; i < M; i ++) {
        cin >> a >> b;
        con[a - 1].push_back(b - 1);
        con[b - 1].push_back(a - 1);
        
        vis[a - 1] = true;
        vis[b - 1] = true;
    }
    
    int ans = 0;
    
    for (int i = 0; i < N; i ++)
        if (!vis[i]) {
            con[0].push_back(i);
            con[i].push_back(0);
            
            ans ++;
        }
        
    queue<int> q;
    q.push(1);
    d[1] = 1;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int i = 0; i < con[cur].size(); i ++) {
            if (d[con[cur][i]] == 0) {
                d[con[cur][i]] = d[cur] + 1;
                q.push(con[cur][i]);
            }
        }
    }
    
    if (d[0] < 6) {
        cout << "0" << endl;
        return (0);
    }
    
    q.push(0);
    d2[0] = 1;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int i = 0; i < con[cur].size(); i ++) {
            if (d2[con[cur][i]] == 0) {
                d2[con[cur][i]] = d2[cur] + 1;
                q.push(con[cur][i]);
            }
        }   
    }
    
    for (int i = 0; i < N; i ++)
        pastures.push_back(ii(d[i], i));
    
    sort(pastures.begin(), pastures.end());
    
    for (int i = 1; i < pastures.size(); i ++) {
        int cur = pastures[i].s;
        
        for (int j = 0; j < con[cur].size(); j ++)
            bad[con[cur][j]] = true;
        
        for (int j = 0; j < i; j ++) {
            int nxt = pastures[j].s;
            
            if (bad[nxt])
                continue;
            
            if (d2[cur] <= 1 + d2[nxt]) {
                if (d[nxt] + 1 + d2[cur] >= 7) {
                    ans ++;
                    d[cur] = min(d[cur], d[nxt] + 1);
                }
            }    
        }
        
        for (int j = 0; j < con[cur].size(); j ++)
            bad[con[cur][j]] = false;
    }

    cout << (ans) << endl;
    return (0);
}