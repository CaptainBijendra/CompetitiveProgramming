#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define INF 20009
#define MAX_N 19
#define f first
#define s second
#define int short

using namespace std;

typedef pair<int, int> ii;

vector<ii> con[MAX_N];

int N, M;

int32_t main() {
    cin >> N >> M;

    int** DP = new int*[(1 << MAX_N)];

    for (int i = 0; i < (1 << N); i ++)
        DP[i] = new int[N];

    int a, b, c;
    for (int i = 0; i < M; i ++) {
        cin >> a >> b >> c;
        a --; b --;
        
        con[a].push_back(ii(b, c));
        con[b].push_back(ii(a, c));
    }
    
    for (int i = 0; i < (1 << N); i ++) 
        for (int j = 0; j < N; j ++) 
            DP[i][j] = INF;
    
    for (int i = 0; i < N; i ++)
        DP[(1 << i)][i] = 0;
    
    for (int i = 0; i < (1 << N); i ++) {
        for (int j = 0; j < N; j ++) { //Current Index
            for (int k = 0; k < con[j].size(); k ++) {
                if (i & (1 << con[j][k].f))
                    continue;
                
                DP[(i | (1 << con[j][k].f))][con[j][k].f] = min((int)DP[(i | (1 << con[j][k].f))][con[j][k].f], DP[i][j] + con[j][k].s);
            }
        }
    }
    
    int ans = INF;
    
    for (int i = 0; i < N; i ++)
        ans = min(ans, DP[(1 << N) - 1][i]);
    
    for (int i = 0; i < (1 << N); i ++)
        delete [] DP[i];
    
    delete [] DP;
    
    cout << ans << endl;
    return (0);
}