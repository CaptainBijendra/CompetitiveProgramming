#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

#define MAX_N 1005
#define MAX_M 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

ii rock[MAX_N], lift[MAX_N];

int DP_W[MAX_M], DP_L[MAX_M];
int N, M;

int main() {
    cin >> N >> M;
    
    //first = weight, second = value
    for (int i = 0; i < N; i ++)
        cin >> lift[i].f >> lift[i].s;
    
    //first = lift, second = cost
    for (int i = 0; i < M; i ++)
        cin >> rock[i].f >> rock[i].s;
    
    for (int i = 1; i < MAX_M; i ++) {
        DP_W[i] = -1000 * MAX_M;
        DP_L[i] = 1000 * MAX_M;
    }
    
    for (int j = 0; j < M; j ++) {
        for (int i = MAX_M - 1; i >= 0; i --) {
            if (i + rock[j].f < MAX_M)
                DP_W[i + rock[j].f] = max(DP_W[i + rock[j].f], DP_W[i] + rock[j].s);
        }
    }    
    
    for (int j = 0; j < N; j ++) {
        for (int i = MAX_M - 1; i >= 0; i --) {
            if (i + lift[j].f < MAX_M)
                DP_L[i + lift[j].f] = min(DP_L[i + lift[j].f], DP_L[i] + lift[j].s);
        }        
    }
    
    for (int i = 1; i < MAX_M; i ++)
        DP_W[i] = max(DP_W[i], DP_W[i - 1]);
    
    for (int i = MAX_M - 2; i >= 0; i --)
        DP_L[i] = min(DP_L[i], DP_L[i + 1]);
    
    int ans = 0;
    
    for (int i = 0; i < MAX_M; i ++) {
        ans = max(ans, DP_W[i] - DP_L[i]);
    }

    cout << ans << endl;
    return (0);
}