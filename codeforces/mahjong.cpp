#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <string.h>
#include <math.h>

#define MAX_N 1000005
#define f first
#define s second

using namespace std;

int ar[MAX_N], cnt[MAX_N], DP[MAX_N][3][3];
int N, M;

int main() {
    cin >> N >> M;
    
    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
        cnt[ar[i]] ++;
    }

    int ans = 0;

    for (int i = 1; i <= M; i ++) { 
        for (int j = 0; j <= 2; j ++) {
            for (int k = 0; k <= 2; k ++) {
                for (int l = 0; l <= 2; l ++) {     
                    if (cnt[i] >= (j + k + l)) {
                        DP[i + 1][k][l] = max(DP[i + 1][k][l], DP[i][j][k] + l + (cnt[i] - (j + k + l)) / 3);
                    
                        if (cnt[i + 1] >= (k + l) && cnt[i + 2] >= l)
                            ans = max(ans, DP[i + 1][k][l]);
                    }
                }
            }
        }
    }
    
    cout << ans << endl;
    return (0);
}