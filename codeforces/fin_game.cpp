#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>

#define INF 200000009
#define MAX_N 4005
#define f first
#define s second

using namespace std;

int DP[MAX_N][155][155];
int ar[MAX_N], pre[MAX_N];
int N;

int sum(int a, int b) {
    return (pre[b] - pre[a] + ar[a]);
}

int solve(int l, int diff, int k) {
    if (DP[l][diff][k] > -INF)
        return (DP[l][diff][k]);
    
    int r = (N - 1 - l - diff);
    int pos1 = INF, pos2 = INF;
    
    if (l + k >= N || l + k - 1 > r)
        return (0);
    
    if (l > r)      
        return (0);
    
    if (l + k - 1 <= r) {
        if (r - k + 1 > l + k - 1)
            pos1 = min(pos1, sum(l, l + k - 1) - sum(r - k + 1, r) + solve(l + k, diff, k));
        else
            pos1 = min(pos1, sum(l, l + k - 1));
    }
    
    if (l + k - 1 <= r) {
        if (r - k > l + k - 1)
            pos1 = min(pos1, sum(l, l + k - 1) - sum(r - k, r) + solve(l + k, diff + 1, k + 1));
        else if (pos1 == INF)
            pos1 = min(pos1, sum(l, l + k - 1));
    }
    
    if (l + k <= r) { 
        if (r - k > l + k)
            pos2 = min(pos2, sum(l, l + k) - sum(r - k, r) + solve(l + k + 1, diff, k + 1));
        else
            pos2 = min(pos2, sum(l, l + k));
    }
    
    if (l + k <= r) {
        if (r - k - 1 > l + k) 
            pos2 = min(pos2, sum(l, l + k) - sum(r - k - 1, r) + solve(l + k + 1, diff + 1, k + 2));
        else if (pos2 == INF)
            pos2 = min(pos2, sum(l, l + k));
    }
    
    DP[l][diff][k] = max((pos1 == INF ? -INF : pos1), (pos2 == INF ? -INF : pos2));
    return (DP[l][diff][k]);
}

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
    
        if (i == 0)
            pre[i] = ar[i];
        else
            pre[i] = pre[i - 1] + ar[i];
    }

    for (int i = 0; i < MAX_N; i ++) 
        for (int j = 0; j < 155; j ++) 
            for (int k = 0; k < 155; k ++) 
                DP[i][j][k] = -INF;

    solve(0, 0, 1);
        
    cout << (DP[0][0][1] == -INF ? 0 : DP[0][0][1]) << endl;
    return (0);
}