#include <iostream>
#include <fstream>

#define MAX_R 105
#define MAX_C 105

#define MOD 1000000007

int board[MAX_R][MAX_C], DP[MAX_R][MAX_C];
int R, C, K, i, j, k, l;

using namespace std;

int main() {
    ifstream fin ("hopscotch.in");
    ofstream fout ("hopscotch.out");

    fin >> R >> C >> K;

    for (i = 0; i < R; i ++) {
        for (j = 0; j < C; j ++) {
            fin >> board[i][j];
        }
    }

    DP[0][0] = 1;

    for (i = 0; i < R; i ++) {
        for (j = 0; j < C; j ++) {
            for (k = i + 1; k < R; k ++) {
                for (l = j + 1; l < C; l ++) {
                    if (board[k][l] != board[i][j]) {
                        DP[k][l] += DP[i][j];
                        DP[k][l] %= MOD;
                    }
                }
            }
        }
    }

    fout << DP[R - 1][C - 1] << endl;
    return (0);
}