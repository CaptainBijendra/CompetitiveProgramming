#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>

#define INF 2000000000009
#define MAX_N 1505
#define f first
#define s second

using namespace std;

typedef pair<long long, long long> ii;

ii seg[MAX_N];

long long DP[MAX_N][MAX_N], ar[MAX_N], pre[MAX_N], far[MAX_N];
long long N, S, M, K, bad = 0;

long long sum(long long i, long long j, long long num) {
    i --;
    j --;

    return (pre[j] - pre[i] + (ar[i] <= num));
}

bool pos(long long num) {
    pre[0] = (ar[0] <= num);
    for (long long i = 1; i < N; i ++)
        pre[i] = pre[i - 1] + (ar[i] <= num);
    
    for (long long i = 0; i <= N + 1; i ++) 
        for (long long j = 1; j <= M + 1; j ++) 
            DP[i][j] = -INF;
    
    long long ans = -INF;

    for (long long i = 0; i <= N; i ++) { //What index we're at
        for (long long j = 0; j <= M; j ++) { //How many segments we've chosen
            long long k = far[i];

            if (i <= seg[k].s) {
                DP[seg[k].s + 1][j + 1] = max(DP[seg[k].s + 1][j + 1], DP[i][j] + sum(i, seg[k].s, num));
            
                if (j + 1 <= M)
                    ans = max(ans, DP[seg[k].s + 1][j + 1]);
            }
            
            DP[i + 1][j] = max(DP[i + 1][j], DP[i][j]);
        }
    }
    
    return (ans >= K);
}

int main() {
    cin >> N >> S >> M >> K;

    for (long long i = 0; i < N; i ++) {
        cin >> ar[i];
        far[i] = S;
    }

    for (long long i = 0; i < S; i ++)
        cin >> seg[i].f >> seg[i].s;
    
       
    seg[S].f = -1;
    seg[S].s = -1;
    
    sort(seg, seg + S);

    for (long long i = 0; i <= N + 1; i ++) {
        for (long long j = 0; j < S; j ++) {
            if (seg[j].f <= i) {
                if (seg[far[i]].s < seg[j].s)
                    far[i] = j;
            }
        }
    } 

    long long low = 0;
    long long hi = INF;
    
    while (low < hi) {
        long long mid = (low + hi) / 2;
    
        if (!pos(mid))
            low = mid + 1;
        else
            hi = mid;
    } 
    
    cout << (low > INF / 2ll - 3ll ? -1ll : low) << endl;
    return (0);
}