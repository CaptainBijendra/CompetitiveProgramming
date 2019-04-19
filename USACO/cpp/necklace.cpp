#include <iostream>
#include <algorithm>
#include <string.h>

#define MAX_N 10005
#define MAX_M 1005
#define f first
#define s second

using namespace std;

string str, str2;

short DP[MAX_N][MAX_M];

int recover[MAX_M][26];
int N, M;

int main() {
    cin >> str;
    cin >> str2;
    
    N = str.size();
    M = str2.size();
    
    for (int i = 1; i < M; i ++) {
        int p = recover[i - 1][str2[i - 1] - 'a'];
        recover[i - 1][str2[i - 1] - 'a'] = i;
        
        for (int j = 0; j < 26; j ++)
            recover[i][j] = recover[p][j];
    }    
    
    recover[M - 1][str2[M - 1] - 'a'] = M;
    
    for (int j = 1; j < M; j ++)
        DP[0][j] = -MAX_N;

    for (int i = 1; i <= N; i ++) {
        for (int j = 0; j < M; j ++) {
            if (recover[j][str[i - 1] - 'a'] < M)
                DP[i][recover[j][str[i - 1] - 'a']] = max(DP[i][recover[j][str[i - 1] - 'a']], (short)(DP[i - 1][j] + 1));
        }
        
        for (int j = 0; j < M; j ++)
            DP[i + 1][j] = DP[i][j];
    }

    short ans = 0;
    
    for (int i = 0; i < M; i ++) {
        ans = max(ans, DP[N][i]);
    }
    
    cout << N - ans << endl;
    return (0);
}