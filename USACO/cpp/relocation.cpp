/*
ID: akommul1
LANG: C++ 
PROB: relocation
*/

#include <iostream>
#include <fstream>

#define MAX_N 10005
#define MAX_K 6
#define MAX_INT 100000

using namespace std;

int dist[MAX_N][MAX_N], DP[MAX_N][MAX_N], mark[MAX_K];
int N, M, K, i, j, k;

int main() {
    ifstream fin ("relocation.in");
    ofstream fout ("relocation.out");
    
    fin >> N >> M >> K;
    
   for (i = 0; i < N; i ++) {
        for (j = 0; j < N; j ++) {
            dist[i][j] = MAX_INT;
        }
    }
    
    for (i = 0; i < K; i ++) { fin >> mark[i]; }
    for (i = 0; i < M; i ++) {
        fin >> j >> k;
        fin >> dist[j - 1][k - 1];
    }
    
    return (0);
}