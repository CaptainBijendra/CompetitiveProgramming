#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define INF 2000000000000009
#define MAX_P 10005
#define MAX_N 505
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> pii;

pii cow[MAX_N];

long long F[MAX_N], C[MAX_N], DP[MAX_P][2];
long long K, E, N;

int main() {
    cin >> K >> E >> N;
    
    int a, b, c;
    
    for (int i = 0; i < N; i ++)
        cin >> cow[i].f >> cow[i].s.f >> cow[i].s.s;
    
    sort(cow, cow + N);
    
    for (int i = 0; i < N; i ++) {
        F[i] = cow[i].s.f;
        C[i] = cow[i].s.s;
    }

    long long ans = INF;

    for (int j = 0; j <= K; j ++) {
        DP[j][0] = INF;
        DP[j][1] = INF;
        
        if (j <= F[0])
            DP[j][1] = j * C[0];
    }

    for (int i = 1; i < N; i ++) {
        for (int j = 0; j <= K; j ++) {
            DP[j][0] = DP[j][1];
            DP[j][1] = INF;
            
            if (j <= F[i])
                DP[j][1] = j * C[i];
        }
        
        int X = INF;
        
        for (int j = 0; j <= K; j ++) { //Current Amount
            //DP[k][1] = k * C[i] + min(DP[k][1], DP[j][0] + j * j * d[i] - j * C[i])
            //                                    k - F[i] <= j <= k
            
            for (int k = j; k <= min(K, j + F[i]); k ++) { //After Amount
                DP[k][1] = min(DP[k][1], DP[j][0] + j * j * (cow[i].f - cow[i - 1].f) + (k - j) * C[i]);
            }
        }

        ans = min(ans, DP[K][1] + K * K * (E - cow[i].f));
    }
    
    cout << ans << endl;
    return (0);
}