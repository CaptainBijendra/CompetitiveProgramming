#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 18
#define f first
#define s second

using namespace std;

long long ar[MAX_N], DP[(1 << MAX_N)][MAX_N];
int N, K;

int main() {
    cin >> N >> K;
    
    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
        DP[(1 << i)][i] = 1ll;
    }
    
    for (int i = 0; i < (1 << N); i ++) {
        for (int j = 0; j < N; j ++) {
            if (i & (1 << j)) {
                for (int k = 0; k < N; k ++) {
                    if (k == j)
                        continue;
                    
                    if ((i & (1 << k)) && (abs(ar[j] - ar[k]) > K)) {
                        DP[i][j] += DP[i ^ (1 << j)][k];
                    }        
                }
            }
        }
    }
        
    long long sum = 0ll;    
    
    for (int i = 0; i < N; i ++)
        sum += DP[(1 << N) - 1][i];
    
    cout << sum << endl;
    return (0);
}