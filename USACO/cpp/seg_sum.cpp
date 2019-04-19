#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>

#define MOD 998244353 
#define MAX_N 20
#define MAX_K 12

//What is our length
//What numbers have we used so far

long long DP[MAX_N][MAX_K][(1 << MAX_K)];
long long L, R, K;

using namespace std;

int calc(int a) {
    return (-1);
}

int main() {
    cin >> L >> R >> K;
    
    long long mult = 1;
    
    for (int i = 1; i < MAX_N; i ++) { 
        for (int j = 1; j <= 9; j ++) {
            DP[i][1][(1 << j)] = (DP[i - 1][1][(1 << j)] + (j * mult) % MOD);
            DP[i][1][(1 << j)] %= MOD;
        }
        
        mult *= 10;
        mult %= MOD;
    }
    
    for (int i = 2; i < MAX_K; i ++) { //Number of different digits we're allowed to use
        for (int j = 0; j < MAX_N; j ++) { //How large is our current number
            for (int k = 0; k < (1 << MAX_K); k ++) { //What is our current bitmask state
                for (int l = 0; l < MAX_K; l ++) { 
                    if (k & (1 << l)) { cnt ++; }
                }
                    
            }
        }
    }

    cout << (calc(R) - calc(L - 1) + MOD) % MOD << endl;
    return (0);
}