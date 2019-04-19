#include <iostream>
#include <fstream>
#include <algorithm>

#define MAX_N 5005
#define MAX_M 100005
#define MAX_INT 1000000

using namespace std;

int DP[MAX_N], stalls[MAX_N], C[MAX_M];
int i, j, N, M;

int main() {
    ifstream fin ("umbrella.in");
    ofstream fout ("umbrella.out");
    
    fin >> N >> M;
    
    for (i = 0; i < N; i ++) { fin >> stalls[i]; }
    for (i = 1; i <= M; i ++) { fin >> C[i]; }
    
    sort(stalls, stalls + N);
    
    for (i = 0; i < N; i ++) { DP[i] = C[stalls[i] - stalls[0] + 1]; }

    for (i = 1; i < N; i ++) {
        for (j = i; j >= 0; j --) {
            DP[i] = min(C[stalls[i] - stalls[j] + 1] + DP[j - 1], DP[i]);
        }
    }
    
    fout << DP[N - 1] << endl;
    return (0);
}
