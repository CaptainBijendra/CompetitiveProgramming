#include <iostream>
#include <fstream>

#define MAX_N 105

using namespace std;

int board[MAX_N], DP[MAX_N][MAX_N], sum[MAX_N][MAX_N];
int N, i, j;

int max(int a, int b) { return (a > b ? a : b); }

int main() {
    ifstream fin ("game1.in");
    ofstream fout ("game1.out");
    
    fin >> N;
    
    for (i = 0; i < N; i ++) { fin >> board[i]; }
    for (i = 0; i < N; i ++) {
        sum[i][i] = board[i];
        
        for (j = i + 1; j < N; j ++) {
            sum[i][j] = sum[i][j - 1] + board[j];
        }
    }
    
    for (i = 0; i < N; i ++) { DP[i][1] = board[i]; }

    for (i = 2; i <= N; i ++) {
        for (j = 0; j <= N; j ++) {
            DP[j][i] = max(board[j] + sum[j + 1][j + i - 1] - DP[j + 1][i - 1],
                           board[j + i - 1] + sum[j][j + i - 2] - DP[j][i - 1]);
        }
    }
    
    fout << DP[0][N] << " " << sum[0][N - 1] - DP[0][N] << endl;
    return (0);
}