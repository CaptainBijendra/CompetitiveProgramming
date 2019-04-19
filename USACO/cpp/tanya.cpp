#include <iostream>
#include <algorithm>
#include <string.h>

#define MAX_N 55
#define MAX_K 2005
#define INF 2000000009
#define f first
#define s second

using namespace std;

int ar[MAX_N], DP[MAX_N][MAX_K];
int N, S, K;

int main() {
    cin >> N >> S >> K;

    for (int i = 0; i < N; i ++)
        cin >> ar[i];

    string str;
    cin >> str;

    int ans = INF;

    for (int i = 0; i < MAX_N; i ++) {
        for (int j = 0; j < MAX_K; j ++) {
            DP[i][j] = INF;
        }
    }
    
    for (int i = 0; i < N; i ++)
        DP[i][ar[i]] = abs(S - 1 - i);

    for (int j = 0; j < MAX_K; j ++) {
        for (int i = 0; i < N; i ++) {
            for (int k = 0; k < N; k ++) {
                if (ar[k] > ar[i] && str[k] != str[i]) {
                    DP[k][j + ar[k]] = min(DP[k][j + ar[k]], DP[i][j] + abs(k - i));
                }
            }
        }
    }
    
    for (int i = 0; i < MAX_N; i ++) 
        for (int j = K; j < MAX_K; j ++) 
            ans = min(ans, DP[i][j]);     
     
    cout << (ans == INF ? -1 : ans) << endl;
    return (0);
}