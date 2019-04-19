#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>

#define MAX_N 1005
#define INF 200000000

using namespace std;

int DP[MAX_N][MAX_N];
int A[MAX_N], B[MAX_N];

int N, X, Y, Z;
int NA, NB;

int main() {
    ifstream fin ("landscaping.in");
    ofstream fout ("landscaping.out");
    
    fin >> N >> X >> Y >> Z;
    
    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    
    for (int i = 0; i < N; i ++) {
        int j, k; fin >> j >> k;
        
        while (j >= 0) { A[NA ++] = i; j --; } 
        while (k >= 0) { B[NB++] = i; k --; } 
    }   
    
    for (int i = 0; i < MAX_N; i ++) { 
        for (int j = 0; j < MAX_N; j ++) { DP[i][j] = INF; }
    }
    
    for (int i = 0; i < max(NA, NB); i ++) 
    { DP[i][0] = i * Y; DP[0][i] = i * X; }
    
    for (int i = 0; i < NA; i ++) {
        for (int j = 0; j < NB; j ++) {
            DP[i + 1][j + 1] = min(DP[i + 1][j + 1], DP[i][j] + Z * (abs(A[i] - B[j])));
            DP[i + 1][j] = min(DP[i + 1][j], DP[i][j] + Y);
            DP[i][j + 1] = min(DP[i][j + 1], DP[i][j] + X);
        }
    }
    
    fout << DP[NA - 1][NB - 1] << endl;
    return (0);
}