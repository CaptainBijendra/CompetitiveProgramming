#include <iostream>

#define MAX_N 5005
#define MOD 1000000007

using namespace std;

char com[MAX_N];

int DP[MAX_N][MAX_N];
int N;

int main() {
    cin >> N;
    for (int i = 0; i < N; i ++) { cin >> com[i]; }
     
    DP[0][0] = 1;

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            if (DP[i][j]) {
                if (com[i] == 'f') { DP[i + 1][j + 1] = (DP[i + 1][j + 1] + DP[i][j]) % MOD; } 
                else {
                    for (int k = 0; k <= j; k ++) 
                    { DP[i + 1][k] = (DP[i + 1][k] + DP[i][j]) % MOD; }
                }
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < N; i ++) { ans += DP[N - 1][i]; }
    
    cout << ans << endl;
    return (0);
}