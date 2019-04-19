#include <iostream>
#include <algorithm>
#include <vector>

#define INF 2000000009
#define MAX_N 9

using namespace std;

int DP[MAX_N][MAX_N][(1 << MAX_N)][2][(1 << 3)];

//DP state DP[# of rows][parity of columns (1 << columns)][parity of current row (either 0 or 1)][parity of current 3 by 3 matrix (1 << 3)]

int ar[MAX_N][MAX_N];
int N;

int main() {
    N = 9;

    for (int i = 0; i < N; i ++) {
        string str;
        cin >> str;

        for (int j = 0; j < N; j ++)
            ar[i][j] = (str[j] == '0' ? 0 : 1);
    }

    for (int i = 0; i < N; i ++)
        for (int jj = 0; jj < N; jj ++) 
            for (int j = 0; j < (1 << N); j ++)
                for (int k = 0; k < 2; k ++)
                    for (int l = 0; l < (1 << 3); l ++)
                        DP[i][jj][j][k][l] = INF;

    if (ar[0][0] == 1) {
        DP[0][0][1][1][1] = 0;
        DP[0][0][0][0][0] = 1;
    }
    
    else {
        DP[0][0][1][1][1] = 1;
        DP[0][0][0][0][0] = 0;
    }

    int prev = -1;
    bool reset, row_reset;

    for (int i = 0; i < N; i ++) { //row
        for (int j = 0; j < N; j ++) { //column
            for (int k = 0; k < (1 << N); k ++) { //parity of columns
                for (int l = 0; l < 2; l ++) { //parity of current row
                    for (int m = 0; m < (1 << 3); m ++) { //parity of current 3 by 3 matrix
                        reset = false;
                        row_reset = false;
                        
                        if (i == 0 && j == 0)
                            continue;
                        else if (j > 0)
                            prev = DP[i][j - 1][k][l][m];
                        else { 
                            row_reset = true;
                            
                            if ((i % 3) != 0)
                                prev = DP[i - 1][N - 1][k][0][m];
                            else { 
                                prev = DP[i - 1][N - 1][k][0][0];
                                reset = true;
                            }
                        }
                        
                        if (prev < 0 || prev >= INF)
                            continue;
                        
                        if (!reset && !row_reset) { 
                            DP[i][j][(k ^ (1 << j))][!l][(m ^ (1 << (j / 3)))] = min(DP[i][j][(k ^ (1 << j))][!l][(m ^ (1 << (j / 3)))], prev + (ar[i][j] == 0));
                            DP[i][j][k][l][m] = min(DP[i][j][k][l][m], prev + (ar[i][j] == 1));
                        }
                        
                        else if (row_reset && !reset) {
                            DP[i][j][(k ^ (1 << j))][1][(m ^ (1 << (j / 3)))] = min(DP[i][j][(k ^ (1 << j))][1][(m ^ (1 << (j / 3)))], prev + (ar[i][j] == 0));
                            DP[i][j][k][0][m] = min(DP[i][j][k][0][m], prev + (ar[i][j] == 1));
                        }
                        
                        else if (reset && row_reset) {
                            DP[i][j][(k ^ (1 << j))][1][(1 << (j / 3))] = min(DP[i][j][(k ^ (1 << j))][1][(1 << (j / 3))], prev + (ar[i][j] == 0));
                            DP[i][j][k][0][0] = min(DP[i][j][k][0][0], prev + (ar[i][j] == 1));    
                        }
                    }
                }    
            }
        }
    }

    cout << DP[N - 1][N - 1][0][0][0] << endl;
    return (0);
}