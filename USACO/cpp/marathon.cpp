#include <iostream>
#include <fstream>

#define MAX_N 505
#define MAX_K 505
#define MAX_INT 1000000

int x[MAX_N], y[MAX_N], DP[MAX_K][MAX_N];
int N, K, i, j, k;

using namespace std;

int min(int a, int b) { return (a < b ? a : b); }
int abs(int a) { return (a < 0 ? (a * -1) : a); }

int main() {
    ifstream fin ("marathon.in");
    ofstream fout ("marathon.out");

    fin >> N >> K;

    for (i = 0; i < N; i ++) { fin >> x[i] >> y[i]; }
    
    for (i = 0; i <= K; i ++) {
        for (j = 0; j < N; j ++) {
            DP[i][j] = MAX_INT;
        }
    }

    DP[0][0] = 0;

    for (i = 0; i <= K; i ++) {
        for (j = 0; j < N; j ++) {
            for (k = 0; k <= K && k <= j; k ++) {
                DP[i][j] = min(DP[i][j - k] + abs(x[j] - x[j - k]) + abs(y[j] - y[j - k]), 
                               DP[i - k - 1][j - k]); 
            }
        }
    }

    for (i = 0; i <= K; i ++) {
        for (j = 0; j < N; j ++) {
            cout << i << " " << j << " " << DP[i][j] << endl;
        }
    }

    return (0);
}