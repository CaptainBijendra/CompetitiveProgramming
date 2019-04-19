#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX_N 1005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

vector<int> DP[MAX_N];
vector<ii> con[MAX_N];

int N, M, K;

int main() {
    cin >> N >> M >> K;
    
    int a, b, c;
    for (int i = 0; i < M; i ++) {
        cin >> a >> b >> c;
        
        con[a - 1].push_back(ii(b - 1, c));
    }
    
    for (int i = N - 1; i >= 0; i --) {
        sort(DP[i].begin(), DP[i].end());
        
        for (int j = 0; j < con[i].size(); j ++) {
            int n = con[i][j].f;
            
            if (i == N - 1)
                DP[n].push_back(con[i][j].s);
            
            for (int k = 0; k < min(100, (int)DP[i].size()); k ++)
                DP[n].push_back(con[i][j].s + DP[i][k]);
        }
    }
    
    sort(DP[0].begin(), DP[0].end());
    
    for (int i = 0; i < min(K, (int)DP[0].size()); i ++)
        cout << DP[0][i] << endl;

    for (int j = K - DP[0].size(); j > 0; j --)
        cout << "-1" << endl;
        
    return (0);
}