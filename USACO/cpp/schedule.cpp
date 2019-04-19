#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];

int T[MAX_N], in[MAX_N], DP[MAX_N];
int N, M;

void DFS (int ind) {
    DP[ind] = T[ind];
    
    for (int i = 0; i < con[ind].size(); i ++) {
        DFS (con[ind][i]);
        DP[ind] = max(DP[ind], DP[con[ind][i]] + T[ind]);
    }
}

int main() {
    cin >> N >> M;
    
    for (int i = 0; i < N; i ++)
        cin >> T[i];
    
    int a, b;
    for (int i = 0; i < M; i ++) {
        cin >> a >> b;
        con[a - 1].push_back(b - 1);
        in[b - 1] ++;
    }
    
    int ans = 0;
    
    for (int i = 0; i < N; i ++) {
        if (in[i] == 0) {
            DFS (i);
            ans = max(ans, DP[i]);
        }
    }
    
    cout << ans << endl;
    return (0);
}