#include <iostream>
#include <fstream>
#include <vector>

#define INF 200000000
#define MAX_N 16
#define MAX_K 30

using namespace std;

vector<int> ord;

int DP[(1 << (MAX_N))][MAX_K];

int min_sum[MAX_N][MAX_N];

int c[MAX_N][MAX_N];
int N, K;

int main() {
    ifstream fin ("partition.in");
    ofstream fout ("partition.out");
    
    fin >> N >> K;
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) { fin >> c[i][j]; }
    }
    
    for (int i = 0; i < (1 << (N - 1)); i ++) {
        for (int j = 0; j < (N - 1); j ++)
        { if (i & (1 << j)) { ord.push_back(j); } }
        
        for (int j = 0; j < N; j ++) { 
            for (int k = 0; k < N; k ++) { min_sum[i][j] = INF; }
        }
        
        for (int j = 0; j < N; j ++) {
            for (int k = 0; k < N; k ++) { 
                
            }
        }
        
        for (int j = ord.size(); j < K; j ++) {
            for (int k = 0; k < N; k ++) {
                for (int l = k + 1; k < N; l ++) { 
                    DP[i][j + 1] = min(DP[i][j + 1], max(DP[i][j], min_sum[k][l]));
                                   // min sum of squares from adding an extra horizontal line at k
                }
            }
        }
        
        ord.clear();
    }
    
    return (0);
}