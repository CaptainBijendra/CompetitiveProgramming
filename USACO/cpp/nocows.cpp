#include <iostream>
#include <fstream>

#define MAX_N 201
#define MAX_K 101

int tree[MAX_K][MAX_N], smaller[MAX_K][MAX_N];
int N, K, i, j, k, l, mult;

using namespace std;

int main() {
    ifstream fin ("nocows.in");
    ofstream fout ("nocows.out");
    
    fin >> N >> K;
    
    tree[1][1] = 1;
    
    for (i = 2; i <= K; i ++) {
        for (j = 0; j <= N; j ++) {
            for (k = 0; k <= j - k - 1; k ++) {
                for (l = 1; l <= N - 2; l ++) {
                    if (k != j - k - 1) { mult = 2; } 
                    else { mult = 1; }
                
                    tree[i][j] += (tree[i - 1][k] * tree[l][j - k - 1] * mult);
                    tree[i][j] += (tree[l][k] * tree[i - 1][j - k - 1] * mult);
                    tree[i][j] %= 9901;
                }
        
                tree[i][j] += (tree[i - 1][k] * tree[i - 1][j - k - 1] * mult);
            }
        }
    }
    
    fout << tree[K][N] << endl;
    return (0);
}
