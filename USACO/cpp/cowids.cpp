#include <iostream>
#include <fstream>

#define MAX_K 15
#define MAX_L 35

int DP[MAX_K][MAX_L];
int N, K, i, j;

using namespace std;

int main() {
    ifstream fin ("cowids.in");
    ofstream fout ("cowids.out");

    fin >> N >> K;

    if (K == 1) { 
        fout << "1";
        for (i = 0; i < N - 1; i ++) { fout << "0"; }
        fout << endl;
        return (0);
    }

    DP[1][1] = 1;

    for (i = 1; i <= K; i ++) {
        for (j = 2; j < MAX_L; j ++) {
            DP[i][j] = DP[i - 1][j - 1] + DP[i][j - 1];
        }
    }
    
    fout << DP[K][N] << endl;
    return (0);
}