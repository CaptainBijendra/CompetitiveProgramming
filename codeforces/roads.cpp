#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

vector<ii> con[MAX_N];

bool vis[MAX_N];

int deg[MAX_N], cnt[MAX_N], color[MAX_N];
int N, K, ans;

void DFS (int ind, int col) {
    vis[ind] = true;
    
    int c = 1;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        if (!vis[con[ind][i].s]) {
            if (c == col)
                c ++;
            
            c = min(c, ans);
            
            color[con[ind][i].f] = c;
            DFS (con[ind][i].s, c);
            c ++;
        }
    }
}

int main() {
    cin >> N >> K;
    
    int a, b;
    for (int i = 0; i < N - 1; i ++) {
        cin >> a >> b;
        deg[a - 1] ++;
        deg[b - 1] ++;
        
        con[a - 1].push_back(ii(i, b - 1));
        con[b - 1].push_back(ii(i, a - 1));
    }
    
    for (int i = 0; i < N; i ++)
        cnt[deg[i]] ++;
        
    int sum = 0;
    
    ans = 0;
    for (int i = MAX_N - 1; i >= 0; i --) {
        sum += cnt[i];
        
        if (sum > K) {
            ans = i;
            break;
        }
    }
    
    DFS (0, 0);
    
    cout << ans << endl;
    for (int i = 0; i < N - 1; i ++)
        cout << color[i] << " ";

    cout << endl;
    return (0);
}