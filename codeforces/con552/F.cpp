#include <iostream>
#include <algorithm>
#include <vector>

#define INF 200000000000009
#define MAX_N 200005
#define MAX_K 2005
#define f first
#define s second

using namespace std;

long long offer[MAX_K];
long long ar[MAX_N];

long long pre[MAX_N];
long long DP[MAX_K];

long long N, M, K;

int main() {
    cin >> N >> M >> K;
    
    for (long long i = 0; i < N; i ++)
        cin >> ar[i];
        
    sort(ar, ar + N);
    
    for (long long i = 0; i < N; i ++) {
        if (i == 0)
            pre[i] = ar[i];
        else
            pre[i] = pre[i - 1] + ar[i];
    }
    
    long long x, y;
    for (long long i = 0; i < M; i ++) {
        cin >> x >> y;
    
        if (x > K)  
            continue;
        
        offer[x] = max(offer[x], y);
    }
    
    for (long long i = 0; i < K; i ++)
        DP[i] = (long long)INF;
    
    if (offer[1])
        DP[0] = 0;
    else    
        DP[0] = ar[0];
    
    for (long long i = 1; i < K; i ++) {
        for (long long j = 1; j <= K; j ++) {
            if (i - j < -1)
                continue;
            
            DP[i] = min(DP[i], DP[i - j] + pre[i] - pre[i - j + offer[j]]);
        }
    }
    
    cout << DP[K - 1] << endl;
    return (0);
}