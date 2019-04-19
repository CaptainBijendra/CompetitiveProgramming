#include <iostream>
#include <algorithm>
#include <fstream>

#define MAX_N 1005
#define MOD 1000000007

using namespace std;

long long DP[MAX_N][MAX_N];
long long N, M, K;

int main() {
    ifstream fin ("spainting.in");
    ofstream fout ("spainting.out");
    
    fin >> N >> M >> K;
    
    DP[0][1] = M;

    for (long long i = 1; i < N; i ++) {
        for (long long j = 1; j < K; j ++) {
            DP[i][1] += (M - 1) * DP[i - 1][j];
            DP[i][1] %= MOD;
            
            if (j + 1 < K) { 
                DP[i][j + 1] += DP[i - 1][j];
                DP[i][j + 1] %= MOD;
            }
        }
    }
    
    long long ans = 0ll;
    long long fin_ans = 1;
    
    for (long long i = 0; i < K; i ++) {
        ans += DP[N - 1][i];
        ans %= MOD;
    }

    for (long long i = 0; i < N; i ++) {
        fin_ans *= M;
        fin_ans %= MOD;
    }
    
    fout << (fin_ans - ans + MOD) % MOD << endl;
    return (0);
}