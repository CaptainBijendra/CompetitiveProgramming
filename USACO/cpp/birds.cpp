#include <iostream>
#include <fstream>

#define MAX_N 1005
#define MAX_B 10005

using namespace std;

//DP[i][j]: i = tree, j = birds accumulated, DP[i][j] = mana_left;

int DP[MAX_N][MAX_B];
int birds[MAX_N], cost[MAX_N];

int N, W, B, X;

int main() {
    ifstream fin ("birds.in");
    ofstream fout ("birds.out");
    
    fin >> N >> W >> B >> X;
    
    for (int i = 0; i < N; i ++) { fin >> birds[i]; }
    for (int i = 0; i < N; i ++) { fin >> cost[i]; }
    
    DP[0][0] = W;
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < MAX_B; j ++) {
            if (DP[i][j] > 0) {
                DP[i + 1][j] = max(DP[i + 1][j], min(DP[i][j] + X, W));
            }
            
            if (j + 1 <= birds[])
        }
    }
}