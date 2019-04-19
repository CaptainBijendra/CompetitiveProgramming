#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string.h>

#define MAX_N 10005
#define f first
#define s second

using namespace std;

int DP[MAX_N * 10], ar[MAX_N], cnt[MAX_N];
int N, T;

int main() {
    cin >> N >> T;
    
    for (int i = 0; i < N; i ++)
        cin >> ar[i];
    
    for (int i = 0; i < N; i ++)
        cin >> cnt[i];
    
    for (int i = 1; i < MAX_N; i ++)
        DP[i] = MAX_N * 100;
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j <= cnt[i]; j ++) {
            int sum = ar[i] * j;
            
            for (int k = T; k >= 0; k --) 
                DP[sum + k] = min(DP[sum + k], DP[k] + j);
        }
    }
    
    int ans = MAX_N * 100;
    
    for (int i = T; i < MAX_N; i ++) {
        if (DP[i] != MAX_N * 100 && DP[i - T] != MAX_N * 100)
            ans = min(ans, DP[i] + DP[i - T]);
    }

    cout << (ans == MAX_N * 100 ? -1 : ans) << endl;
    return (0);
}