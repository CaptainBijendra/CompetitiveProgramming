#include <iostream>
#include <algorithm>
#include <vector>

#define INF 2000000009
#define MAX_N 2005
#define f first
#define s second

using namespace std;

int ar[MAX_N], pre[MAX_N], DP[MAX_N][MAX_N], max_dp[MAX_N][MAX_N];
int N;

int sum(int i, int j) {
    if (i > j)
        return (0);

    return (pre[j] - pre[i] + ar[i]);
}

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i ++)
        cin >> ar[i];
    
    pre[0] = ar[0];    
    for (int i = 1; i < N; i ++)
        pre[i] = pre[i - 1] + ar[i];
    
    for (int i = 0; i < N; i ++) 
        DP[N - 1][i] = ar[N - 1];
        
    int cnt = 1;
    
    for (int i = 1; i <= N; i ++) {
        max_dp[N - 1][i] = max(max_dp[N - 1][i - 1], max(DP[N - 1][cnt], DP[N - 1][cnt + 1]));
        cnt += 2;
    }
    
    for (int i = N - 2; i >= 0; i --) { //Cur index
        for (int j = 1; j <= N; j ++) { //How many we previously took
            if (i + j <= N) { 
                DP[i][j] = sum(i, i + j - 1) + sum(i + j, N - 1) - max_dp[i + j][j];
            }        
        }
        
        cnt = 1;
        for (int j = 1; j <= N; j ++) {
            max_dp[i][j] = max(max_dp[i][j - 1], max(DP[i][cnt], DP[i][cnt + 1]));
            cnt += 2;
        }
    }
    
    cout << max(DP[0][1], DP[0][2]) << endl;
    return (0);
}