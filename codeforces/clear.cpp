#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 505
#define f first
#define s second

using namespace std;

string str;

int DP[MAX_N][MAX_N];
int N;

int main() {
    cin >> N;
    cin >> str;
    
    for (int i = 0; i < N; i ++)
        for (int j = i; j < N; j ++)
            DP[i][j] = MAX_N;
    
    for (int i = 0; i < N; i ++)
        DP[i][i] = 1;
    
    for (int len = 2; len <= N; len ++) {
        for (int l = 0; l < N; l ++) {
            int r = (l + len - 1);
            
            if (r >= N)
                break;
            
            DP[l][r] = min(DP[l][r], DP[l + 1][r] + 1);
            
            for (int j = l + 1; j <= r; j ++)
                if (str[j] == str[l])
                    DP[l][r] = min(DP[l][r], DP[l + 1][j - 1] + DP[j][r]);
        }
    }
    
    cout << DP[0][N - 1] << endl;
    return (0);
}
 