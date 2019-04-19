#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string.h>
#include <math.h>

#define INF 2000000009
#define MAX_N 201
#define ROUNDS 6
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

bool DP[2 * MAX_N][2 * MAX_N][ROUNDS][ROUNDS][ROUNDS];
int N;

void test(int x, int y) {
    
}

int main() {
    cin >> N;
    
    DP[0][0][0][0][0] = 1;
    
    for (int ii = 1; ii < ROUNDS; ii ++) {
        for (int i = 0; i < MAX_N; i ++) {
            for (int j = 0; j < MAX_N; j ++) {
                int mx = (ii == 5 ? 15 : 25);
                
                for (int jj = 0; jj < 3; jj ++) {
                    for (int kk = 0; kk < 3; kk ++) { 
                        for (int k = mx; k <= 200; k ++) {
                            DP[i + k][j + (k - 2)][ii][jj + 1][kk] |= DP[i][j][ii - 1][jj][kk];
                            DP[i + (k - 2)][j + k][ii][jj][kk + 1] |= DP[i][j][ii - 1][jj][kk];
                        }
                
                        for (int k = 0; k <= mx - 2; k ++) {
                            DP[i + mx][j + k][ii][jj + 1][kk] |= DP[i][j][ii - 1][jj][kk];
                            DP[i + k][j + mx][ii][jj][kk + 1] |= DP[i][j][ii - 1][jj][kk];
                        }
                    }
                }     
            }    
        }
    }

    int a, b, x = 0, y = 0;
    for (int i = 0; i < N; i ++) {
        cin >> a >> b;
        
        x = -1;
        y = -1;
        
        for (int i = 0; i < 3; i ++) {
            if (DP[a][b][3 + i][3][i]) {
                x = 3;
                y = i;
                
                break;        
            }
        }
        
        if (x == -1 && y == -1) {
            for (int i = 2; i >= 0; i --) {
                if (DP[a][b][3 + i][i][3]) {
                    x = i;
                    y = 3;
                    
                    break;
                }
            }
        }
        
        if (x == -1 || y == -1) 
            cout << "Impossible" << endl;
        else {
            cout << x << ":" << y << endl;
            test(x, y);
        }
    }
    
    return (0);    
}