#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MOD 1000000007
#define MAX_N 105
#define f first
#define s second

using namespace std;

int DP[MAX_N][2]; //DP[i] Number of ways to make a path with sum i 
int N, K, D;

int main() {
    cin >> N >> K >> D;
    
    DP[0][0] = 1;
    
    for (int ii = 1; ii < MAX_N; ii ++) { //Current Sum
        for (int i = 1; i <= min(ii, K); i ++) {
            if (i >= D) {
                DP[ii][1] += DP[ii - i][0];
                DP[ii][1] %= MOD;

                DP[ii][1] += DP[ii - i][1];
                DP[ii][1] %= MOD;
                continue;
            }
            
            DP[ii][0] += DP[ii - i][0];
            DP[ii][0] %= MOD;
            
            DP[ii][1] += DP[ii - i][1];
            DP[ii][1] %= MOD;
        }
    }

    cout << DP[N][1] << endl;
    return (0);
}