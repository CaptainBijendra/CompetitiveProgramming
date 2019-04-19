#include <iostream>

#define MAX_N 505
#define f first
#define s second

using namespace std;

int DP[MAX_N], T[MAX_N][MAX_N], P[MAX_N];
int N;

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i ++)
        cin >> P[i];
    
    int ans = 0;
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++)
            cin >> T[i][j];
    
        if (T[0][i] <= P[i]) {
            DP[i] = 1;
            ans = 1;
        }    
    }
    
    DP[0] = 0;
    
    for (int ii = 0; ii < N; ii ++) {
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < N; j ++) {
                if (i == j)
                    continue;
            
                if (P[i] + T[i][j] <= P[j]) {
                    DP[j] = max(DP[j], DP[i] + 1);
                    ans = max(ans, DP[j]);
                }
            }
        }
    }

    cout << ans << endl;
    return (0);
}