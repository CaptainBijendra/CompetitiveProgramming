#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#define MOD 1000000007
#define MAX_N 1005
#define MAX_K 15

using namespace std;

int DP[MAX_N][MAX_N][MAX_K];

int top[MAX_N], bot[MAX_N];
int N, M, K;

int main() {
    ifstream fin ("team.in");
    ofstream fout ("team.out");
    
    fin >> N >> M >> K;
    
    for (int i = 0; i < N; i ++)
        fin >> top[i];
        
    for (int i = 0; i < M; i ++) 
        fin >> bot[i];
    
    sort(top, top + N);
    sort(bot, bot + N);
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) { 
            DP[i][j][1] = (top[i] > bot[j]);
        }
    }

    for (int ii = 1; ii <= K; ii ++) {
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < M; j ++) {
                for (int a = i + 1; a < N; a ++) {
                    for (int b = j + 1; b < M; b ++) {
                        if (top[a] > bot[b]) {
                            DP[a][b][ii + 1] += DP[i][j][ii];
                            DP[a][b][ii + 1] %= MOD;
                        }
                    }
                }
            }
        }
    }
    
    int ans = 0;
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
            ans += DP[i][j][K];
            ans %= MOD;
        }
    }
    
    fout << ans << endl;
    return (0);
} 