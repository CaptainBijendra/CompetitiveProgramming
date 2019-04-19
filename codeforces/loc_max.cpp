#include <iostream>
#include <algorithm>

#define MOD 998244353 
#define MAX_N 100005
#define f first
#define s second

using namespace std;

long long DP[MAX_N][205][2], sum1[205], sum2[205];
long long ar[MAX_N];

long long N;

int main() {
    cin >> N;
    
    for (long long i = 0; i < N; i ++)
        cin >> ar[i];

    if (ar[0] == -1) {
        sum1[0] = 0;
        
        for (long long i = 1; i <= 200; i ++) {
            DP[0][i][0] = 1;
            sum1[i] = sum1[i - 1] + DP[0][i][0];
        }
    }
    
    else {
        DP[0][ar[0]][0] = 1;
        sum1[0] = 0;
        
        for (long long i = 1; i <= 200; i ++) 
            sum1[i] = sum1[i - 1] + DP[0][i][0];
    }
    
    for (long long i = 1; i < N; i ++) {
        if (ar[i] == -1) {
            for (long long j = 1; j <= 200; j ++) {
                //Any number less than this is allowed
                DP[i][j][0] += (sum1[j - 1] + sum2[j - 1]);
                DP[i][j][0] %= MOD;
                
                //Count if we're creating a streak, either with a current streak or a new one
                DP[i][j][1] += DP[i - 1][j][0];
                DP[i][j][1] %= MOD;
            }
            
            //Break the streak
            for (long long j = 1; j <= 200; j ++) {
                DP[i][j][1] += (sum2[200] - sum2[j - 1] + MOD);
                DP[i][j][1] %= MOD;
            }
        }
        
        else {
            //Any number less than our current is allowed
            DP[i][ar[i]][0] += (sum1[ar[i] - 1]) + (sum2[ar[i] - 1]);
            DP[i][ar[i]][0] %= MOD;
            
            //Check streak
            DP[i][ar[i]][1] += DP[i - 1][ar[i]][0];
            DP[i][ar[i]][1] %= MOD;
            
            //Break the streak
            DP[i][ar[i]][1] += (sum2[200] - sum2[ar[i] - 1] + MOD);
            DP[i][ar[i]][1] %= MOD;
        }
        
        sum1[0] = 0;
        sum2[0] = 0;
        for (long long j = 1; j <= 200; j ++) {
            sum1[j] = sum1[j - 1] + DP[i][j][0];
            sum1[j] %= MOD;
            
            sum2[j] = sum2[j - 1] + DP[i][j][1];
            sum2[j] %= MOD;
        }
    }

    cout << (sum2[200]) % MOD << endl;
    return (0);
}